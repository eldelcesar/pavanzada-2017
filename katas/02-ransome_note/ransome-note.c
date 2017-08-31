#include <stdlib.h>
#include <stdio.h>
#include "ransome-note.h"
#include <stdbool.h>

bool canConstruct(char* ransomNote, char* magazine){

  int count, i, j;

  count = 0;

  for (i = 0; ransomNote[i] != '\0'; i++) {
    for (j = 0; magazine[j] != '\0'; j++) {
      if (ransomNote[i] == magazine[j]) {
        magazine[j] = 'X';
        count++;
        break;
      }
    }
  }

  if (count == i) {
    return true;
  }
  else{
    return false;
  }

}
