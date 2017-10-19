#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include "hash.h"
#include "frequent-elements.h"

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize, int* errorCode) {

  int** result = (int**)calloc(*returnSize, sizeof(int*));
  int** counters = (int**)calloc(*numsSize, sizeof(int*));
  hashtable_t *hashtable = ht_create(65536);
  int max = 1;

  for (int i = 0; i < numsSize; i++) {
    char* value[12], counter[12];
    sprintf(value, "%d", nums[i]);

    if (hr_get(hashtable, value) == NULL) {
      sprintf(counter, "%d", 1);
    } else{
      int temp = atoi(hr_get(hashtable, value)) + 1;
      sprintf(counter, "%d", temp);
    }

    ht_set(hashtable, value, counter);
  }

  for (int j = 0; j < numsSize; j++) {
    char* value[12];
    sprintf(value, "%d", nums[j]);
    counters[j] = hr_get(hashtable, value);
  }


  return NULL;
}
