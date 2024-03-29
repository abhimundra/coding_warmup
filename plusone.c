#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int increment_prev = 0;
    *returnSize = digitsSize;
    for (int i = digitsSize -1 ; i >= 0 ; i--) {
        if (digits[i] == 9) {
            digits[i] = 0;
            increment_prev = 1;
        }
        else {
            digits[i] += 1;
            increment_prev = 0;
            break;
        }
    }
    if (increment_prev == 1) {
        int *new_arr = malloc(digitsSize + 1);
        memcpy(new_arr + 1, digits, digitsSize * sizeof(int));
        free(digits);
        digits = new_arr;
        digits[0] = 1;
        *returnSize = digitsSize+1;
    }
    return digits;
}

int main() {

    int *digits = malloc(sizeof(int) * 1);
    int size = 1;
    digits[0] = 9;
    digits = plusOne(digits, size, &size); 
	
}
