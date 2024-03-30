#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int fact(int num) {
		if (num == 1) {
			return 1;
		}
		return num * fact(num-1);
}

int combination(int n, int r) {
	/*
      int numerator = fact(n);
	  int denominator1 = fact(n-r);
	  int denominator2 = fact(r);
	  result = numerator/ denominator1*denominator2;
	  Time complexity =    O( n * r * (n-r))
	*/
	return fact(n)/(fact(n-r)*fact(r));
}

int main() {

	int n = 6;
	int r = 3;

	printf("\ncombination = %u C %u is %u\n",n,r, combination(n,r));
	return 1;

}
