#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "frequent-elements.h"

// Error 100 => Input
// Error 200 => NumsSize < k

/**************************
 * topKFrequentNumbers
 *
 * Given a non-empty array of integers, the function returns the k most frequent elements.
 *
 * @param:
 *  nums: array of integers
 *  numsSize: size of the array 'nums'
 *  k: number of most frequent elements requested
 *  returnSize: the size of the resulting array
 *  errorCode: errorCode, in case something goes wrong
 *
 * @return:
 *  result: the array with the top k most frequent elements
*/
int* topKFrequentNumbers(int* nums, int numsSize, int k, int* returnSize, int* errorCode) {

  //***** VERIFICATION PROCESS *****//
  // Validate Inputs
  if (numsSize < 1) {
    *errorCode = 100;
  }
  if (nums == NULL) {
    *errorCode = 100;
  }
  if (*returnSize < 1) {
    *errorCode = 100;
  }
  if (numsSize < k) {
    *errorCode = 200;
  }

  //***** Init variables *****//
  int *result, *sortedNums, totalNums;
  Number *rankedNums;

  totalNums = 0;
  result = (int*) calloc(*returnSize, sizeof(int));
  sortedNums = sortArray(nums, numsSize);
  rankedNums = rankNumbers(numsSize, sortedNums, &totalNums);

  printf("\nOriginal Array: \n[");
  for (int i = 0; i < numsSize; i++) {
    if (i != numsSize-1) {
      printf("%d, ", nums[i]);
    } else{
      printf("%d", nums[i]);
    }
  }
  printf("]\n\n");

  printf("Sorted Array:\n[");
  for (int i = 0; i < numsSize; i++) {
    if (i != numsSize-1) {
      printf("%d, ", sortedNums[i]);
    } else{
      printf("%d", sortedNums[i]);
    }
  }

  qsort(rankedNums, numsSize, sizeof(Number), cmpNumbers);

  printf("]\n\n");

  printf("Top K Elements:\n");
  for (int j = 0; j < k; j++) {
    result[j] = rankedNums[j].key;
    printf("%d\n", result[j]);
  }
  printf("\n");
  return result;
}

/**************************
 * rankNumbers
 *
 * Creates an array of Numbers, where each element has a key and the frequency in the array
 *
 * @param:
 *  nums: array of integers
 *  numsSize: size of the array 'nums'
 *  total: number of different values in the array will be saved here
 *   -> Example: [1,1,1,2,2,3,3], total = 3
 *
 * @return:
 *  ranked: the array with Numbers, ranked with their frequency
*/
Number* rankNumbers(int numsSize, int* nums, int* total){
  int prev, value, counter, currentIndex;
  Number *ranked;

  ranked = (Number*) calloc(numsSize, sizeof(Number));
  prev = nums[0];
  value = nums[0];
  counter = 0;
  currentIndex = 0;

  for (int i = 0; i < numsSize; i++) {
    prev = value;
    value = nums[i];
    if (prev == value) {
      counter++;
    }
    else{
      ranked[currentIndex] = initNumber(prev, counter);
      currentIndex++;
      counter = 1;
    }
    if (i == numsSize-1) {
      prev = value;
      ranked[currentIndex] = initNumber(prev, counter);
      currentIndex++;
    }
  }
  *total = currentIndex;
  return ranked;
}

/**************************
 * cmpNumbers
 *
 * Comparing function for qsort; arranged so that the array will be sorted descending
*/
int cmpNumbers (const void * a, const void * b) {
  Number *a1 = (Number*)a;
  Number *b1 = (Number*)b;
  return (-1)*((*a1).freq - (*b1).freq);
}

/**************************
 * initNumber
 *
 * Initializes a Number, with its key and the frequency
 *
 * @param:
 *  key: integer in the list
 *  frequency: frequency of this integer in the list
 *
 * @return:
 *  num: the array with the top k most frequent elements
*/
Number initNumber(int key, int freq){
  Number num;
  num.key = key;
  num.freq = freq;
  return num;
}

/**************************
 * sortArray
 *
 * Sorts given array
 *
 * @param:
 *  nums: integer in the list
 *  numsSize: frequency of this integer in the list
 *
 * @return:
 *  numbers: sorted array
*/
int* sortArray(int* nums, int numsSize){
  int i, j, a, n;
  int *numbers;
  n = numsSize;
  numbers = (int*) calloc(n, sizeof(int));
  for (i = 0; i < n; ++i)
      numbers[i] = nums[i];
  for (i = 0; i < n; ++i)
  {
      for (j = i + 1; j < n; ++j)
      {
          if (numbers[i] > numbers[j])
          {
              a =  numbers[i];
              numbers[i] = numbers[j];
              numbers[j] = a;
          }
      }
  }
  return numbers;
}
