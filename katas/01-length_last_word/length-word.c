#include <stdlib.h>
#include <stdio.h>
#include "length-word.h"

/**************
 * lengthOfLastWord
 * Given a string, get the length of the last word
 * The program will determine when the last word actually starts (from right to left)
   and then count its length.
 * @param:
 *  str: string
 * @return
 *  integer with length of last word
*/
int lengthOfLastWord(char* str) {
  int i, j, length, count, startCount;

  count = 0;
  startCount = 0;

  // Get Length
  for(i = 0; str[i] != '\0'; i++){}
  length = i;

  // Count the length of last word
  if (length > 0) {
    for (j = (length-1); j >= 0; j--) {
      if (str[j] != ' ') {
        startCount = 1;
        count++;
      }
      if (str[j] == ' ' && startCount == 1) {
        return count;
      }
    }
  }
  return count;
}
