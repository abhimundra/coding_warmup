#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct listNode_s {
	int val;
	struct listNode_s *next;
}listNode_t;

listNode_t* addTwoNumbers(listNode_t* l1, listNode_t* l2){

    int step = 0;
    int temp = 0;
    int carry = 0;
    listNode_t *sum_head = NULL;
    listNode_t *tail = NULL;

    while (l1 != NULL || l2 != NULL) {
        temp = 0;
        if (l1 != NULL) {
            temp += l1->val;
        }
        if (l2 != NULL) {
            temp += l2->val; 
        }
        temp += carry;
        if (temp > 10) {
			temp -= 10;
            carry = 1;
        }
	    else {
			carry = 0;
		}
		listNode_t *new_node = malloc(sizeof(listNode_t));
		if (new_node != NULL) {
				new_node->val = temp;
		}
		if (sum_head == NULL) {
				sum_head = new_node;
				tail = sum_head;
		}
		else {
				tail->next = new_node;
				tail = new_node;
		}
        if (l1 != NULL) {
            l1 = l1->next;
        }
        if (l2 != NULL) {
            l2 = l2->next;
        }
    }
	/*If there is no more element in the list and carry is still one, then its a case of last sum resulting into a carry, for that create a new node and put this carry value there*/
	listNode_t *new_node = malloc(sizeof(listNode_t));
	if (new_node != NULL) {
			new_node->val = carry;
	}
	if (sum_head == NULL) {
			sum_head = new_node;
			tail = sum_head;
	}
	else {
			tail->next = new_node;
			tail = new_node;
	}
    return sum_head;
}

int main() {

	int node_list1[] = {8,4,3,4};
	int node_list2[] = {9,1,3};


	listNode_t *head1 = NULL;
	listNode_t *head2 = NULL;
	listNode_t *prevNode = NULL;
	listNode_t *sum = NULL;
	
	for (int i = 0; i < sizeof(node_list1) / sizeof(node_list1[0]); i++) {
		listNode_t *node = calloc(1,sizeof(listNode_t));
		if (node != NULL) {
			node->val = node_list1[i];
		}
		if (head1 == NULL) {
			head1 = node;
		}
		else {
			prevNode->next = node;
		}
		prevNode = node;
	}

	for (int i = 0; i < sizeof(node_list2) / sizeof(node_list2[0]); i++) {
		listNode_t *node = calloc(1,sizeof(listNode_t));
		if (node != NULL) {
			node->val = node_list2[i];
		}
		if (head2 == NULL) {
			head2 = node;
		}
		else {
			prevNode->next = node;
		}
		prevNode = node;
	}

    sum = addTwoNumbers(head1, head2);

    while (sum != NULL) {
		printf (" Val = %u", sum->val);
		sum = sum->next;
	}

	return 1;

}
