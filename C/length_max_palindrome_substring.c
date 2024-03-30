#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int bool;

bool isPalindrome(char *s)
{
	char *start = s;
	char *end = &s[strlen(s)-1];
	while (*start == *end && start <= end) {
		start++;
		end--;
	}
	if (start > end) {
		return 1;
	}
	else {
		return 0;
	}
	
}

int check_and_update(char c, char *map)
{
	char *temp = map;
	while (*temp != '\0') {
		temp++;
	}
	if (*temp == '\0')
	{
		*temp = c;	
	}
	else {
		return 0;
	}
	return 1;
}

int find_max_substring_length(char *s, char **substring)
{
		char *c = s;
		char *map1 = calloc(1,strlen(s));
		char *current_max_substring = NULL;
		while (*c != '\0') {
				if (!check_and_update(*c, map1)) {
						if (current_max_substring == NULL) {
								current_max_substring = calloc(1,strlen(map1));
								memcpy(current_max_substring,map1, strlen(map1));
						}
						else if ((current_max_substring != NULL) && (strlen(map1) > strlen(current_max_substring))) {
								current_max_substring = realloc(current_max_substring, strlen(map1));
								memcpy(current_max_substring,map1, strlen(map1));
						}
						memset(map1, 0, strlen(map1));
						continue;
				}
			   c++;
		}
		if (strlen(map1) > strlen(current_max_substring)) {
			*substring = map1;
			free(current_max_substring);
		}
		else {
			*substring = current_max_substring;
			free(map1);
		}
	   return strlen(*substring);
}



int main()
{
	char *substring = NULL;
	// test 1
	char *s1 = "pwwkew";
	int len = 0;
    len = find_max_substring_length(s1, &substring);  
	printf("\ntest1: , Input string = %s, Max substring found is %s with length = %u\n", s1, substring, len);
	free(substring);
	// test 2
	char *s2 = "aaaaa";
    len = find_max_substring_length(s2, &substring);  
	printf("\ntest2: , Input string = %s, Max substring found is %s with length = %u\n", s2, substring, len);
	free(substring);
	// test 3
	char *s3 = "abcabcbb";
    len = find_max_substring_length(s3, &substring);  
	printf("\ntest3: , Input string = %s, Max substring found is %s with length = %u\n", s3, substring, len);
	free(substring);

	return 0;
}
