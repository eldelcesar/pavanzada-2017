#include <stdio.h>
#include <stdlib.h>
#include "minunit.h"
#include "island-perimeter.h"

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
  int result;
  int expected;
  int **grid, gridRowSize, gridColSize;

  gridRowSize = 4;
  gridColSize = 4;

  grid = (int**) calloc(gridRowSize, sizeof(int*));
  for (int i = 0; i < gridRowSize; i++) {
    grid[i] = (int*)calloc(gridColSize, sizeof(int));
  }

  grid[0][0] = 0;
  grid[0][1] = 1;
  grid[0][2] = 0;
  grid[0][3] = 0;
  grid[1][0] = 1;
  grid[1][1] = 1;
  grid[1][2] = 1;
  grid[1][3] = 0;
  grid[2][0] = 0;
  grid[2][1] = 1;
  grid[2][2] = 0;
  grid[2][3] = 0;
  grid[3][0] = 1;
  grid[3][1] = 1;
  grid[3][2] = 0;
  grid[3][3] = 0;

  expected = 16;
  result = islandPerimeter(grid, gridRowSize, gridColSize);

  muAssert("error, expected result was 16", expected == result);
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
