#include<stdio.h>
#include<stdlib.h>

typedef struct node_s {
	int data;
	struct nodes_s *next;
}node_t;

node_t *head = NULL;

node_t *allocNode(int data)
{
	node_t *node = (node_t *) malloc(sizeof(node_t));
	if (node != NULL) {
		node->data = data;
		node->next = NULL;
	}
	return node; 	
}

void insertNode(node_t *node) {
		if (node != NULL ) {
				if (head == NULL) {
						head = node;
				}
				else {
					node->next = head;
					head = node;	
				}
		}
}


void deleteNode(node_t *node) {
		node_t *temp = head;
		if (node != NULL ) {
				while (temp != NULL) {
						node_t *prev = head;
						if (temp->data != node->data) {
							prev = temp;
							temp = temp->next;
						}
						else {
							prev->next = temp->next;
							free(temp);	
						}
				}
		}
}


int main() 
{
	int arr[10] = {1,3,5,6,7,9};
	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
	}
}
