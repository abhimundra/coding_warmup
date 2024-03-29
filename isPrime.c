#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define TRUE 1
#define FALSE 0

int isPrime(int num) {
	
	for (int i = 2; i*i <= num; i++) {
		if (num % i == 0) {
			return FALSE;
		}
	}
	return TRUE;
}


int main () {

	int num = 10;
	printf("\n Input number = %d, is Prime = %s\n", num, isPrime(num) ? "true":"false");	

}
