#include <stdio.h>
#include <stdlib.h>
#include "minunit.h"
#include "palindrome-pairs.h"

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
// int wordsSize, int** columnSizes, int* returnSize
static char * testPalindromePairsUnit() {
  char **words;
  int wordsSize;
  int *returnSize;
  int **columnSizes;
  int **result;
  int **expected;

  /* CASE 1
  returnSize = 2;

  wordsSize = 3;
  words = (char**)calloc(wordsSize, sizeof(char*));
  // ["bat", "tab", "cat"]
  words[0] = "bat"; words[1] = "tab"; words[2] = "cat";*/

  /* CASE 2 */
  returnSize = (int*)malloc(sizeof(int));
  *returnSize = 4;

  wordsSize = 5;
  words = (char**)calloc(wordsSize, sizeof(char*));
  // ["abcd", "dcba", "lls", "s", "sssll"]
  words[0] = "abcd"; words[1] = "dcba"; words[2] = "lls"; words[3] = "s"; words[4] = "sssll";

  expected = (int**)calloc(*returnSize, sizeof(int*));
  result = palindromePairs(words, wordsSize, columnSizes, returnSize);

  muAssert("Error, wtf", result == expected);
  return 0;
}

static char * allTests() {
  muRunTest(testPalindromePairsUnit);
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
