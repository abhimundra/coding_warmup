#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


/* 0 1 1 2 3 5 8 13 .. */


int fibonacci(int num) {
		if (num <= 0 ) {
			return 0;
		}
		if (num == 1) {
			return 1;
		}
		return fibonacci(num-1) + fibonacci(num-2);
}

int main() {

	for (int i = 0; i < 20; i++) {
			printf("\nFibonacci number at postion %u is %u \n",i, fibonacci(i));
	}

	return 1;

}
