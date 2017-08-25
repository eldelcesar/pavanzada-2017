#include <stdio.h>
#include <stdlib.h>
#include "two-sum.h"

int main (int argn, char **argv){
  int nums[] = {-1,-2,-3,-4,-5};
  int target = -8;
  int numsSize = 5;
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
