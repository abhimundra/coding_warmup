#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>


typedef struct vector_s {
	char *str;
	int len;
	int curr_pos;
}vector_t;

void zigzag_fill(char *s, char **zigzag_str, int numRows)
{
		char *c = s;
		*zigzag_str = calloc(1,strlen(s));
		int cnt_row_val = 0;
		int op = 0;   /*0 - Increment, 1 - decrement*/
		vector_t *v = NULL;
		int j = 0;
		int row = 0; 

		v = calloc(1, sizeof(vector_t) * numRows);
	
		for (j = 0; j < numRows; j++) {
			v[j].str = calloc(1, strlen(s)/numRows);
			v[j].len = strlen(s)/numRows;
			v[j].curr_pos = 0;
		}

	    j = 0;
		while (*c != '\0') {
				v[cnt_row_val].str[v[cnt_row_val].curr_pos++] = *c++; 
				if (cnt_row_val == numRows-1) {
						op = 1;
				}
				else if (cnt_row_val == 0) {
						op = 0;
				}
				if (op) {
						cnt_row_val--;
				}
				else {
						cnt_row_val++;
				}
		}

		int offset = 0;		
		for (j = 0; j < numRows; j++) {
				memcpy(*zigzag_str + offset, v[j].str, v[j].curr_pos); 
				offset += v[j].curr_pos;
		}
}



int main()
{
	char *substring = NULL;
	// test 1
	char *s1 = "paypalishiring";
	int num_rows = 3;

	char *ret_str = NULL;
	
    zigzag_fill(s1, &ret_str, num_rows); 

	printf("\nString = %s\n", ret_str);

	free(ret_str);

	// test 2
	num_rows = 4;

    zigzag_fill(s1, &ret_str, num_rows); 
	printf("\nString = %s\n", ret_str);

	free(ret_str);

	return 0;
}
