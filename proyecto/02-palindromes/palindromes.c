#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "palindromes.h"

int validPalindrome(char* palindrome) {

  int length, half, i, isPalindrome;
  isPalindrome = 0;

  // Get length
  length = strlen(palindrome);

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
