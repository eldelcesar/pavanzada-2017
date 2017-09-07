#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "palindrome-pairs.h"

/**************************
 * palindromePairs
 *
 * Given a set of unique words, determine the distinct indices(i, j) in the given
 * list that, when concatenated, are palindromes
 *
 * @param:
 *  words: array of words
 *  wordsSize: size of the array 'words'
 *  columnSizes: array of the number of columns of each result
 *  returnSize: the size of the resulting array
 *
 * @return:
 *  result: the array of arrays with the pair of indices of words that form palindromes
*/
int** palindromePairs(char **words, int wordsSize, int **columnSizes, int *returnSize, int *errorCode) {
  int **result;
  int length;
  int countPalindromes;

  // Init Parameters
  countPalindromes = 0;

  // Init Columns
  *columnSizes = (int*)calloc(*returnSize, sizeof(int));
  for (int x = 0; x < *returnSize; x++) {
    *columnSizes[x] = 2;
  }
  // Check errors of init
  if (*columnSizes == NULL) {
    *errorCode = 100;
  }

  // Init Result
  result = (int**)calloc(*returnSize, sizeof(int*));
  for (int y = 0; y < *returnSize; y++) {
    result[y] = (int*)calloc(*columnSizes[y], sizeof(int));
  }
  // Check errors of init
  if (*columnSizes == NULL) {
    *errorCode = 100;
  }

  // Magic Box
  for (int i = 0; i < wordsSize; i++) {
    for (int j = 0; j < wordsSize; j++) {
      // Must be different indices
      if (i != j) {
        length = strlen(words[i]) + strlen(words[j]);

        // Check errors for empty/null words
        if (strlen(words[j]) == 0 || words[i] == NULL) {
          *errorCode = 200;
        }
        if (strlen(words[j]) == 0 || words[j] == NULL) {
          *errorCode = 200;
        }

        // Creates the word (possible palindrome)
        char palindrome[length];
        strcpy(palindrome, words[i]);
        strcat(palindrome, words[j]);
        printf("[%d,%d] Word: %s\n", i, j, palindrome);


        // Checks if word is actually a palindrome
        if (isPalindrome(palindrome, length)) {
          result[countPalindromes][0] = i;
          result[countPalindromes][1] = j;
          countPalindromes++;
          printf("%s is a palindrome\n", palindrome);
        }
      }
    }
  }

  // Prints the result
  printResult(result, *returnSize, 2);
  return result;
}



/**************************
 * isPalindrome
 *
 * Given a word, determine if the word is a palindrome
 *
 * @param:
 *  palindrome: word that could be a palindrome
 *  length: length of the word
 *
 * @return:
 *  isPalindrome: if == 1 the word is a palindrome; otherwise it's not
*/
int isPalindrome(char* palindrome, int length){
  int half, i, isPalindrome;

  isPalindrome = 0;

  // Get Half
  if (length%2 == 1) {
    half = (length-1)/2;
  } else{
    half = length/2;
  }

  // Check if it's a palindrome
  for (i = 0; i < half; i++) {
    printf("%c is equal to %c? ", palindrome[i], palindrome[length-1-i]);
    if (palindrome[i] == palindrome[length-1-i]) {
      isPalindrome = 1;
      printf("True\n");
    } else{
      isPalindrome = 0;
      printf("False\n\n");
      break;
    }
  }

  return isPalindrome;
}



/**************************
 * printResult
 *
 * Prints the given array of arrays with the result
 *
 * @param:
 *  result: the array of arrays of int with the result
 *  rows: number of rows in the result
 *  columns: number of columns in the result
 *
 * @return:
 *  none
*/
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
