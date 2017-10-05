#include <stdio.h>
#include <stdlib.h>
#include "minunit.h"
#include "keyboard-row.h"

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
  char** words;
  char** expected;
  char** result;
  int wordsSize;
  int returnSize;
  int errorCode;


  wordsSize = 4;
  returnSize = 2;
  errorCode = 0;
  words = (char**)calloc(wordsSize, sizeof(char*));
  words[0] = "Hello"; words[1] = "Alaska"; words[2] = "Dad"; words[3] = "Peace";

  expected = (char**)calloc(returnSize, sizeof(char*));
  expected[0] = "Alaska"; expected[1] = "Dad";
  
  reault = (char**)calloc(returnSize, sizeof(char*));
  result = findWords(words, wordsSize, &returnSize, &errorCode);

  for (int i = 0; i < returnSize; i++) {
    printf("%s\n", result[i]);
  }

  muAssert("error, testUnit 1 != 1", 1 == 1);
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
