#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    unsigned int i = 0;
    int remainder = 0;
    int *returnIndexArr = NULL;
    if (nums != NULL && numsSize !=0 && returnSize != NULL) {
      for (i = 0; i < numsSize; i++) {
          if (nums[i] <= target) {
              remainder = target - nums[i];
              if (returnIndexArr == NULL) {
                returnIndexArr = malloc(sizeof(int));
                if (returnIndexArr != NULL) {
                    *returnIndexArr = i;
                    *returnSize = 1;
                }
                else {
                    *returnSize = 0;
                    return NULL;
                }
              }
              else {
                  int *temp = NULL;
                 temp = realloc(returnIndexArr, sizeof(int) * (*returnSize +1));
                 if (temp != NULL) {
                    free(returnIndexArr);
                    *returnSize = 0;
                    return NULL;
                 }
                 free(returnIndexArr);
                 returnIndexArr = temp;
                 *returnSize +=1;
              }
              if (!remainder) {
                  break;
              }
          }
      }
  }
  return returnIndexArr;
}

int main() {

    int nums[4] = {1,4,8,10};
	int target = 9;	

	int *returnArr = NULL;
	int size = 0;

	returnArr = twoSum(nums,sizeof(nums)/sizeof(nums[0]), target, &size);

	return 1;

}
