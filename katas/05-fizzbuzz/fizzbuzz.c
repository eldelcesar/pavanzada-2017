#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fizzbuzz.h"

/*
 * fizzBuzz
 * The function prints 1 to n representation. If the number is multiple of 3,
 * prints "Fizz" and if it is multiple of 5 "Buzz"; if it is multiple of both
 * of them, it prints "FizzBuzz".
 * @param: n, returnSize.
 * @return: array of characters with the string representation
 */
char** fizzBuzz(int n, int* returnSize) {

  int isFizzBuzz;
  char str[15] = "";
  char** result = (char**) calloc(*returnSize, sizeof(char*));

  for (int i = 0; i < n; i++) {
    isFizzBuzz = 0;
    result[i] = (char*) calloc(15, sizeof(char));
    sprintf(str, "%d", i+1);

    // Fizz
    if ( (i+1)%3 == 0 ) {
      isFizzBuzz = 1;
      strcpy(str, "");
      strcat(str, "Fizz");
    }
    // Buzz
    if ( (i+1)%5 == 0 ) {
      if (isFizzBuzz == 0) {
        strcpy(str, "");
      }
      strcat(str, "Buzz");
    }

    // Result
    strcpy(result[i], str);
  }
  return result;
}
