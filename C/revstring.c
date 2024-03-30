#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse(char *s, char *leftPtr, int sSize) {
    if (s < (leftPtr + sSize - 1)) {
        reverse(++s,leftPtr, sSize);
    }
    
    if (leftPtr < s) {
        char temp;
        temp = *s;
        *s = *leftPtr;
        *leftPtr = temp;
        leftPtr++;
    }
}


void reverseString(char* s, int sSize){

    char *leftPtr = s;
    char *stref = s;
    
    if (sSize > 2) {
        reverse(stref,leftPtr,sSize);
    }
}


int main()
{
	char s[10] = {'h','e','l','l','o'};
	reverseString(s,strlen(s));
	printf("Sting %s", s);
	return 0;
}
