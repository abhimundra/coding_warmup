#include<stdio.h>
#include<stdlib.h>

struct my_struct{
	int a;
	int b;
	char c;
	int d;
};


#define offset_of(s,m)   (size_t)&(((s *)0)->m)

#define container_of(s,m,t) (t *)(m - offset_of(s,m)) 


int main() {
#if 0
	struct my_struct s1;	

	printf("\n%lu\n", offset_of(struct my_struct,d));
	printf("\n%p\n", container_of(s1,&s1.c,struct my_struct));
#endif
	return 1;

}
