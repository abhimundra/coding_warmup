#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int fact(int num) {
		if (num == 1) {
			return 1;
		}
		return num * fact(num-1);
}

int permutation(int n, int r) {
	return fact(n)/fact(n-r);
}

int main() {

	int n = 6;
	int r = 3;

	printf("\nPermuation = %u P %u is %u\n",n,r, permutation(n,r));
	return 1;

}
