#include <stdio.h>
#include <stdlib.h>

int main (int argn, char** argv){
  int length;
  length = lengthOfLastWord("Hello World");
  printf("result: %d\n", length);
  return 0;
}

int lengthOfLastWord(char* s) {
  int i, j, last, length;

  for(i = 0; s[i] != '\0'; i++){}
  last = i;

  for(j = last; s[j] != ' '; j--){}
  length = last - j - 1;

  return length;
}
