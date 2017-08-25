#include <stdlib.h>
#include <stdio.h>
#include "length-word.h"
#include <string.h>

int main (int argn, char** argv){
  int length, i, j;
  char* str;

  for (i = 0; argv[i] != '\0'; i++) {}
  str = malloc(i);
  for (j = 1; j < i; j++) {
    strcat(str, argv[j]);
    strcat(str, " ");
  }

  length = lengthOfLastWord(str);
  printf("Word: %s\nLast word length: %d\n", str, length);
  return 0;
}
