#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize){
    int duplicate_check_state = nums[0];
    int duplicate_start_idx = -1;
    int count = 1;

    for (int i = 1; i < numsSize; i++) {
	if (nums[i] == duplicate_check_state) {
		if (duplicate_start_idx == -1) {
			duplicate_start_idx = i;	
		}
		nums[i] = -1;	
	}
	else {
	   nums[duplicate_start_idx] = nums[i];
	   count++;
	   duplicate_check_state = nums[i];
	   duplicate_start_idx +=1; 
	}
    }
    return count;
}

int main () {

	int num[] = {1,1,1,2,2,2,3,4};
	removeDuplicates(num, sizeof(num)/sizeof(num[0]));
		

}
