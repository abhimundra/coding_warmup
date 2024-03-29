#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct listNode_s {
	int val;
	struct listNode_s *next;
}listNode_t;

int traversal_head(listNode_t *node) {
	if (node != NULL) {
		printf("\n val =  %u\n", node->val);
		traversal_head(node->next);
	}
}

int traversal_tail(listNode_t *node) {
	if (node != NULL) {
		traversal_tail(node->next);
		printf("\n val =  %u\n", node->val);
	}
}

int main() {

	int node_list[] = {1,2,3,4};

	listNode_t *head = NULL;
	listNode_t *prevNode = NULL;
	
	for (int i = 0; i < sizeof(node_list) / sizeof(node_list[0]); i++) {
		listNode_t *node = calloc(1,sizeof(listNode_t));
		if (node != NULL) {
			node->val = node_list[i];
		}
		if (head == NULL) {
			head = node;
		}
		else {
			prevNode->next = node;
		}
		prevNode = node; 
	}

	printf("\nReverse traversal\n");
	traversal_tail(head);
	printf("\nForward traversal\n");
	traversal_head(head);

	return 1;

}
