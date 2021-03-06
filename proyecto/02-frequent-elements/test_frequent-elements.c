#include <stdio.h>
#include <stdlib.h>
#include "minunit.h"
#include "frequent-elements.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"

int testsRun = 0;

static char * testUnit() {

  int numsSize = 6;
  int returnSize = 2;
  int k = 2;
  int *nums = (int*) calloc(numsSize, sizeof(int));
  int *expected = (int*) calloc(returnSize, sizeof(int));
  int *result;
  int errorCode = 0;
  int flag;

  nums[0] = 3; nums[1] = 2; nums[2] = 1;
  nums[3] = 2; nums[4] = 1;
  nums[5] = 1;

  expected[0] = 1; expected[1] = 2;
  result = topKFrequentNumbers(nums, numsSize, k, &returnSize, &errorCode);

  flag = 1;

  for (int i = 0; i < returnSize; i++) {
    if(expected[i] != result[i]){
      flag = 0;
    }
    // printf("expected[%d] = %d, result[%d] = %d\n", i, expected[i], i, result[i]);
  }

  muAssert("error, result and expected do not match", flag == 1);
  muAssert("internal error, ErrorCode is not 0", errorCode == 0);
  return 0;
}

static char * allTests() {
  muRunTest(testUnit);
  return 0;
}

int main(int argc, char **argv) {
  char *result = allTests();
  if (result != 0) {
    printf("-_-_-_-_-_-_-_,------,      o \n");
    printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
    printf("-_-_-_-_-_-_-~|__( X .X)  +     + \n");
    printf("_-_-_-_-_-_-_- \"\"  \"\" \n");
    printf(KRED "✗ %s \n" RESET, result);
  }
  else {
    printf("-_-_-_-_-_-_-_,------,      o \n");
    printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
    printf("-_-_-_-_-_-_-~|__( ^ .^)  +     + \n");
    printf("_-_-_-_-_-_-_-  \"\"  \"\" \n");
    printf(KGRN " ✓ ALL TESTS PASSED \n" RESET);
  }
  printf("Tests run: %d\n", testsRun);
  return result != 0;
}
