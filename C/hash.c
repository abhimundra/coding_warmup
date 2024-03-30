#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <zlib.h>
#include <string.h>

#define MAX_STRING_VAL 256
#define MAX_HASH_ENTRIES 256

typedef enum err_code_e {
	SUCCESS = 0,
	MEM_ALLOC_FAILED,
	ENTRY_EXISTS,
	FAILURE
}err_code_t;

typedef struct list_s {
	char str[MAX_STRING_VAL];
	struct list_s *next;
	struct list_s *prev;
}list_t;


typedef struct hash_entry_s {
    list_t *list;
	uint8_t num_nodes;
}hash_entry_t;

typedef struct hash_table_s{
	   hash_entry_t *hash_entries;
	   uint64_t num_max_buckets;
	   /*Counters*/
	   uint64_t collisions;
	   uint64_t mem_alloc_failed;
	   uint64_t entry_exists;
	   uint64_t insertions;
	   uint64_t deletions;
}hash_table_t;	


hash_table_t g_hash_tbl;

uint64_t hash_func(char *str) {
	uint64_t hash_val = 0;
	hash_val = crc32(hash_val, (const unsigned char *) str, strlen(str));	
	return hash_val;
}


int init_hash_table(int max_entries) {
	g_hash_tbl.hash_entries = calloc(max_entries,sizeof(hash_entry_t));
	if (NULL == g_hash_tbl.hash_entries) {	
			return -1;
	}
	g_hash_tbl.num_max_buckets = max_entries;
	return 0;
}

int insert_list_node(hash_entry_t *entry, char *str) {
	list_t *node = entry->list;
	list_t *last_node;
	
	if (node ==  NULL) {
			node = calloc(1, sizeof(strlen(str)));
			/*Entry not found till the end of the traversal */
			if (node == NULL) {
					return MEM_ALLOC_FAILED;
			}
			strncpy(node->str, str, strlen(str));
			entry->list = node;
	}
	else {
			do {
					if (!strncmp(node->str, str, strlen(str))) {
							return ENTRY_EXISTS;
					}
					last_node = node;
					node = node->next;
			}while (node != NULL);

			last_node->next = calloc(1, sizeof(strlen(str)));
			/*Entry not found till the end of the traversal */
			if (last_node->next == NULL) {
					return MEM_ALLOC_FAILED;
			}
			strncpy(last_node->next->str, str, strlen(str));
	}
}

int hash_insert(uint64_t hash_index, char *str) {
	int ret_code = SUCCESS;
	ret_code = insert_list_node(&g_hash_tbl.hash_entries[hash_index], str);
	switch (ret_code) {
		case MEM_ALLOC_FAILED:
				g_hash_tbl.mem_alloc_failed++;
				break;
		case ENTRY_EXISTS:
				g_hash_tbl.entry_exists++;
				break;
		default:
				g_hash_tbl.insertions++;
				break;
	}
	return 0;			
}

void insert_entries(char *str[], int num_entries) {
	uint64_t hash_index = 0;

	for (int i = 0; i < num_entries ; i++) {
		if (str[i] != NULL) {
				hash_index = hash_func(str[i]) % MAX_HASH_ENTRIES;
				hash_insert(hash_index, str[i]);
		}
	}
} 



int main() {

	char *str[] = {"Abhishek", "Reena", "Misha", "Ivaansh", "Abhishek"};

	if (init_hash_table(MAX_HASH_ENTRIES)) {
		printf("\nFailed to initialize the hash table\n");
		return -1;
	}

	insert_entries(str, 5);	

}




