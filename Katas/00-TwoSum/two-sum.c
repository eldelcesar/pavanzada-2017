#include <stdio.h>
#include <stdlib.h>
#include "two-sum.h"

int * twoSum(int* nums, int numsSize, int target) {
    int i, j;
    int candidate;
    int *solution;

    solution = malloc(2);

    for(i = 0; i < numsSize; i++){

      // Only applies in case there's only postive integers
      // if(nums[i]) <= target){
        for (j = i+1; j < numsSize; j++) {
          candidate = nums[i] + nums[j];
          if (candidate == target) {
            solution[0] = i;
            solution[1] = j;
            return solution;
          }

        }
      // }
    }
    return NULL;
}
