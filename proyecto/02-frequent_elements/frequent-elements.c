#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "frequent-elements.h"

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize, int* errorCode) {

  int **result = (int**)calloc(*returnSize, sizeof(int*));
  int* sortedNums = sortArray(nums, numsSize);
  Dict *rank = initDictionary(numsSize, errorCode);
  int prev, value, counter;

  prev = nums[0];
  value = nums[0];
  counter = 0;

  for (int i = 0; i < numsSize; i++) {
    prev = value;
    value = nums[i];
    //printf("%d, %d\n", prev, value);
    if (prev == value) {
      counter++;
    }
    else{
      char* key;
      sprintf(key, "%d", prev);
      upsertDictionary(rank, key, (int*) &counter, sizeof(int), errorCode);
      printf("Key: %d, Count: %d\n", prev, counter);
      counter = 1;
    }
    if (i == numsSize-1) {
      prev = value;
      printf("Key: %d, Count: %d\n", prev, counter);
    }
  }

  // Dict *dictionary, char* key, int size, int *errorCode
  int val = getDictonary(rank, "1", sizeof(int), errorCode);
  // printf("VALUE: %d\n", *val);

  /*hashtable_t *hashtable = ht_create(65536);
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
*/
  return NULL;
}


int* sortArray(int* nums, int n){
    int i, j, a;
    int *number;

    number = (int*) calloc(n, sizeof(int));

    for (i = 0; i < n; ++i)
        number[i] = nums[i];

    for (i = 0; i < n; ++i){
        for (j = i + 1; j < n; ++j){
            if (number[i] > number[j]){
                a =  number[i];
                number[i] = number[j];
                number[j] = a;
            }
        }
    }
    for (i = 0; i < n; ++i)
        //printf("%d\n", number[i]);
    return number;
}




/// DICTIONARY **************** //
Dict* initDictionary(unsigned int size, int *errorCode){
  Dict* newDict;
  // Why cast?
  // You are advertising the compiler what will contain
  // that space in memory we are creating
  newDict = (Dict*) calloc(1, sizeof(Dict));

  // Check for error
  if (newDict == NULL) {
    *errorCode = 100;
    return NULL;
  }

  newDict->size = size;
  newDict->elements = (DictElement*) calloc(size, sizeof(DictElement));

  // Check for error
  if (newDict->elements == NULL) {
    *errorCode = 200;
    return NULL;
  }
  *errorCode = 0;
  return newDict;
}

/*hash: form hash value for string s*/
static unsigned hash(char *s, unsigned int size){
  unsigned hashval;
  for (hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;
  return hashval % size;
}

void upsertDictionary(Dict *dictionary, char* key, void* value, int size, int *errorCode){
  if (dictionary == NULL) {
    *errorCode = 100;
    return;
  }
  if (key == NULL) {
    *errorCode = 100;
    return;
  }
  if (value == NULL) {
    *errorCode = 100;
    return;
  }
  if (size <= 0){
      *errorCode = 100;
      return;
  }

  int index = hash(key, dictionary->size);
  dictionary->elements[index].key = key;
  dictionary->elements[index].value = malloc(size);
  if(dictionary->elements[index].value == NULL){
      *errorCode = 100;
      return;
  }
  memcpy(dictionary->elements[index].value,value,size);
  *errorCode = 0;
}

void * getDictionary(Dict *dictionary, char* key, int size, int *errorCode){
  if (dictionary == NULL) {
    *errorCode = 100;
    return NULL;
  }
  if (dictionary->elements == NULL) {
    *errorCode = 100;
    return NULL;
  }
  if (key == NULL) {
    *errorCode = 100;
    return NULL;
  }
  if (size <= 0){
      *errorCode = 100;
      return NULL;
  }

  int index = hash(key, dictionary->size);
  void *result = malloc(size);
  if(result == NULL){
      *errorCode = 100;
      return NULL;
  }
  memcpy(result,dictionary->elements[index].value,size);
  return result;
}
