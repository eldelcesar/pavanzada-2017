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

static char * testPalindromePairsUnit() {
  char **words;
  int wordsSize;
  int *returnSize;
  int **columnSizes;
  int **result;
  int **expected;
  int isCorrect;

  /* CASE 1
   * words = ["abcd", "dcba", "lls", "s", "sssll"]
   * result = [0,1], [1,0], [2,4], [3,2]
  */

  // Init variables
  returnSize = (int*)malloc(sizeof(int));
  *returnSize = 4;
  expected = (int**)calloc(*returnSize, sizeof(int*));
  for (int i = 0; i < *returnSize; i++) {
    expected[i] = (int*)calloc(2, sizeof(int));
  }
  isCorrect = 1;

  // Define words array
  wordsSize = 5;
  words = (char**)calloc(wordsSize, sizeof(char*));
  words[0] = "abcd"; words[1] = "dcba";
  words[2] = "lls"; words[3] = "s"; words[4] = "sssll";

  // Define expected result
  expected[0][0] = 0;
  expected[0][1] = 1;
  expected[1][0] = 1;
  expected[1][1] = 0;
  expected[2][0] = 2;
  expected[2][1] = 4;
  expected[3][0] = 3;
  expected[3][1] = 2;

  // Get Result
  result = palindromePairs(words, wordsSize, columnSizes, returnSize);

  // Verify result
  for (int i = 0; i < *returnSize; i++) {
    for (int j = 0; j < 2; j++) {
      if (expected[i][j] != result[i][j]) {
        isCorrect = 0;
        break;
      }
    }
  }

  muAssert("Error, [0,1], [1,0], [2,4], [3,2] was expected", isCorrect);
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
