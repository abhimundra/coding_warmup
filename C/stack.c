#include<stdio.h>
#include<stdlib.h>

typedef struct list_node_s {
	int val;
	struct list_node_s *next;
}list_node_t;

typedef struct my_stack_s {
	list_node_t *top;
	int size;
}my_stack_t;

/*Stack declaration*/
my_stack_t s;

list_node_t *alloc_node(int val) {

	list_node_t *new_node = (list_node_t *)malloc(sizeof(list_node_t));
	if (new_node != NULL) {
		new_node->val = val;
		return new_node;
	}
	return NULL;
}

void push(my_stack_t *s, list_node_t *node) {
	if (node != NULL) {
		node->next = s->top;
		s->top = node;
		s->size++;				
	}
}

list_node_t *pop(my_stack_t *s) {
	list_node_t *node = s->top;
	if (s->top != NULL) {
		s->top = s->top->next;
		s->size--;
	}
	return node;
}

int min_element(my_stack_t *s) {
	list_node_t *node = s->top;
	int min = 2147483647; 
	while(node != NULL) {
		if (min > node->val) {
			min = node->val;
		}
		node = node->next;
	}
	return min;
}

int get_stack_size(my_stack_t *s) {
	return s->size;
}

void initialize_stack(my_stack_t *s) {

	/*Initialize the function pointer of the stack*/
	s->size = 0;
	s->top = NULL;
}

int main() {

	initialize_stack(&s);
	list_node_t *new_node = alloc_node(10);
	push(&s,new_node);
	new_node = alloc_node(5);
	push(&s,new_node);
	new_node = alloc_node(15);
	push(&s,new_node);
	printf("\n stack size = %u \n", get_stack_size(&s));
	printf("\n min element = %u \n", min_element(&s));
	new_node = pop(&s);
	printf("\n node value = %u \n", new_node->val);
	
		
	
}
