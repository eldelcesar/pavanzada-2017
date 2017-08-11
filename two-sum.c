#include <stdio.h>
#include <stdlib.h>

int * twoSum(int* nums, int numsSize, int target);


int main (int argn, char **argv){
  int nums[] = {2, 7, 14, 1};
  int target = 8;
  int numsSize = 4;

  int *result = twoSum(nums, numsSize, target);
  if (result != NULL && nums[result[0]] + nums[result[1]] == target) {
    printf("PICKLE RICK!!\n");
    printf("SOLUTION: [%d,%d]\n", result[0], result[1]);
  }
  else{
    printf("Noup :(\n");
  }

  free(result);
  return 0;
}

int * twoSum(int* nums, int numsSize, int target) {
    int i, j;
    int candidate;
    int *solution;

    solution = malloc(2);

    for(i = 0; i < numsSize; i++){

      if(nums[i] < target){
        for (j = i+1; j < numsSize; j++) {

          candidate = nums[i] + nums[j];

          if (candidate == target) {
            solution[0] = i;
            solution[1] = j;
            return solution;
          }

        }
      }
    }

    return NULL;
}
