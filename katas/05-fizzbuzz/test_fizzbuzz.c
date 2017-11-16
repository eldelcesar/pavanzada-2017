#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minunit.h"
#include "fizzbuzz.h"

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
  int returnSize, isCorrect;
  char** result, **expected;

  isCorrect = 1;
  returnSize = 15;
  result = (char**) calloc(returnSize, sizeof(char*));
  expected = (char**) calloc(15, sizeof(char*));

  // Initialize the "expected" array
  expected[0] = "1"; expected[1] = "2"; expected[2] = "Fizz";
  expected[3] = "4"; expected[4] = "Buzz"; expected[5] = "Fizz";
  expected[6] = "7"; expected[7] = "8"; expected[8] = "Fizz";
  expected[9] = "Buzz"; expected[10] = "11"; expected[11] = "Fizz";
  expected[12] = "13"; expected[13] = "14"; expected[14] = "FizzBuzz";

  result = fizzBuzz(15, &returnSize);

  // Check for errors
  for ( int i = 0; i < returnSize; i++ ) {
    if ( strcmp(expected[i], result[i]) != 0 ) {
      printf( "Error: %s != %s!\n", expected[i], result[i] );
      isCorrect = 0;
      break;
    }
    printf( "%s\n", result[i] );
  }

  muAssert("Error, the resulting array is not correct", isCorrect == 1);
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
