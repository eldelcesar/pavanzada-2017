#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "palindrome-pairs.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** palindromePairs(char** words, int wordsSize, int** columnSizes, int* returnSize) {
  int **result;
  int length, half;
  int i,j,k;
  int isPalindrome;
  int countPalindromes;

  countPalindromes = 0;

  // Init the columnSizes array
  *columnSizes = (int*)calloc(*returnSize, sizeof(int));
  for (int x = 0; x < *returnSize; x++) {
    *columnSizes[x] = 2;
  }

  // Init the results array
  result = (int**)calloc(*returnSize, sizeof(int*));
  for (int y = 0; y < *returnSize; y++) {
    result[y] = (int*)calloc(*columnSizes[y], sizeof(int));
  }

  for (i = 0; i < wordsSize; i++) {
    //printf("Word %d: %s\n", i, words[i]);
    for (j = 0; j < wordsSize; j++) {
      // Must be different indices
      if (i != j) {
        // Calculates the length and the exact half
        length = strlen(words[i]) + strlen(words[j]);
        if (length%2 == 1) {
          half = (length-1)/2;
        } else{
          half = length/2;
        }

        // Will be checking if word is palindrome
        isPalindrome = 0;

        // Creates the possible palindrome
        char palindrome[length];
        strcpy(palindrome, words[i]);
        strcat(palindrome, words[j]);
        // printf("[%d,%d] Word: %s\n", i, j, palindrome);

        // Checks if word is palindrome
        for (k = 0; k < half; k++) {
          // printf("%c is equal to %c? ", palindrome[k], palindrome[length-1-k]);
          if (palindrome[k] == palindrome[length-1-k]) {
            //printf("True\n");
            isPalindrome = 1;
          } else{
            isPalindrome = 0;
            //printf("False\n\n");
            break;
          }
        }
        if (isPalindrome) {
          result[countPalindromes][0] = i;
          result[countPalindromes][1] = j;
          countPalindromes++;
          // printf("%s is a palindrome\n", palindrome);
        }
      }
    }
  }

  // printResult(result, *returnSize, 2);
  return result;
}



void printResult(int** result, int rows, int columns){
  printf("Result: ");
  for (int i = 0; i < rows; i++) {
    printf("[");
    for (int j = 0; j < columns; j++) {
      printf("%d", result[i][j]);
      if (j != (columns-1)) {
        printf(",");
      }
    }
    printf("]");
    if (i != (rows-1)) {
      printf(", ");
    }
  }
  printf("\n\n");
}
