#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compareStrings(const void* a, const void* b) {
  const char* str1 = *(const char**)a;
  const char* str2 = *(const char**)b;
  return strcmp(str1, str2);
}

int main() {

	char *str1[4] = {"Abhishek", "Ivaansh", "Reena", "Aaditri"};

	qsort(str1, sizeof(str1)/sizeof(*str1), sizeof(*str1), compareStrings); 

	printf("\nSorted Output \n");
	for (int i = 0; i < sizeof(str1)/ sizeof(*str1); i++) {
			printf(" %s", str1[i]);
	}
	printf("\n");

}
