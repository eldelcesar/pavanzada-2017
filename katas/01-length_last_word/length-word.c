#include <stdlib.h>
#include <stdio.h>
#include "length-word.h"

int lengthOfLastWord(char* s) {
  int i, j, length, count, startCount;
  // Count will save the size of the last word
  // Start Count will determine when the last word actually starts (from right to left)
  count = 0;
  startCount = 0;

  // Get the lenght of the complete string
  for(i = 0; s[i] != '\0'; i++){}
  length = i;

  // In case the string is not empty
  if (length > 0) {
    // Traverse the char array from back to front
    for (j = (length-1); j >= 0; j--) {

      // When it detects the last letter of the last word, starts the real count
      if (s[j] != ' ') {
        startCount = 1;
        count++;
      }
      // In case the real count already started and an empty space is found, it stops
      if (s[j] == ' ' && startCount == 1) {
        return count;
      }
    }
  }
  return count;
}
