#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "keyboard-row.h"


/* FIND WORDS
 * Finds if a word can be written with characters in 
 * a single keyboard row
 * @param:
 *  - words: list of words
 *  - wordsSize: the size of the words list
 *. - returnSize: size of the resultant words array
 *. - errorCode: to check errors
 * @return: resultant array of words that can be written in single keyboard row
 * */
char** findWords(char** words, int wordsSize, int* returnSize, int* errorCode) {

  char** result;
  char* word;
  int wordLength;
  int resultCounter;

  result = (char**)calloc(*returnSize, sizeof(char*));
  resultCounter = 0;

  for (int i = 0; i < wordsSize; i++) {
    word = words[i];
    wordLength = strlen(word);
    if(isWordInSingleRow(&word, &wordLength) == 1){
      result[resultCounter] = word;
      resultCounter++;
    }

  }

  return result;
}


/* IS WORD IN SINGLE ROW
* Checks if a word can be written in either of the 3 rows in keyboard
* @param: word and word length
* @return: 1 if it can be written in one row, 0 otherwise*/
int isWordInSingleRow(char** word, int* wordLength){
  const int rowsNumber = 3;
  const char ROW_ONE[20] = {'Q', 'q', 'W', 'w', 'E', 'e', 'R', 'r', 'T', 't',
                            'Y', 'y', 'U', 'u', 'I', 'i', 'O', 'o', 'P', 'p'};
  const char ROW_TWO[18] = {'A', 'a', 'S', 's', 'D', 'd', 'F', 'f', 'G', 'g',
                           'H', 'h', 'J', 'j', 'K', 'k', 'L', 'l'};
  const char ROW_THREE[14] = {'Z', 'z', 'X', 'x', 'C', 'c', 'V', 'v',
                            'B', 'b', 'N', 'n', 'M', 'm'};
  const char* ROWS[rowsNumber] = {ROW_ONE, ROW_TWO, ROW_THREE};


  int row = 0;
  int currentRow = 0;

  for (int i = 0; i < rowsNumber; i++) {
    for (int j = 0; j < *wordLength; j++) {
      for (int k = 0; k < strlen(ROWS[i]); k++) {
        if (k == 0){
          row = i + 1;
        }

        if (*word[j] == ROWS[i][k]) {
          currentRow = i +1;
        }

        if (currentRow != row) {
          return 0;
        }
      }
    }
  }
  return 1;
}
