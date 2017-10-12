#include <stdlib.h>
#include <stdio.h>
#include "island-perimeter.h"

/**************
 * islandPerimeter
 * Given a matrix with 0s and 1s, where 1's mean island and 0's sea, the function will
 * determine the perimeter of the island.
 * @param:
 *  grid (int**): the matrix with the 'map'
 *  gridRowSize (int): number of rows
 *  gridColSize (int): number of columns
 * @return
 *  integer with the perimeter of the island
*/
int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
  int result;
  result = 0;

  for (int i = 0; i < gridRowSize; i++) {
    for (int j = 0; j < gridColSize; j++) {

      switch (grid[i][j]) {
        case 1:
          if (j != gridColSize-1) {
            if (grid[i][j+1] == 0) {
              result++;
            }
          }
          if (i != gridRowSize-1) {
            if (grid[i+1][j] == 0) {
              result++;
            }
          }
          if (i == 0) {
            result++;
          }
          if (i == gridRowSize-1) {
            result++;
          }
          if (j == 0) {
            result++;
          }
          if (j == gridColSize-1) {
            result++;
          }
          break;
          
        case 0:
          if (j != gridColSize-1) {
            if (grid[i][j+1] == 1) {
              result++;
            }
          }
          if (i != gridRowSize-1) {
            if (grid[i+1][j] == 1) {
              result++;
            }
          }
          break;
      }
    }
  }
  return result;
}
