#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

// fact(n) = n * fact(n-1)
//		n = 1,  fact(1) = 1



int fact(int num) {
		if (num == 1) {
			return 1;
		}
		return num * fact(num-1);
}

int main() {

	int n = 3;

	printf("\nFactorial = %u\n", fact(n));

	/*Time Complexity -  n * (n-1) * (n-2) .... 1    =  O(N) */
	return 1;

}
