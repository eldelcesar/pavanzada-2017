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
  int result, rowSize, colSize;
  result = 0;

  rowSize = gridRowSize-1;
  colSize = gridColSize-1;

  for (int i = 0; i < gridRowSize; i++) {
    for (int j = 0; j < gridColSize; j++) {
      // Check if there are any island-sea borders
      if (j != colSize) {
        if (grid[i][j+1] != grid[i][j]) {
          result++;
        }
      }
      if (i != rowSize) {
        if (grid[i+1][j] != grid[i][j]) {
          result++;
        }
      }

      // Check special cases
      if (grid[i][j]) {
        if (i == 0) {
          result++;
        }
        if (i == rowSize) {
          result++;
        }
        if (j == 0) {
          result++;
        }
        if (j == colSize) {
          result++;
        }
      }
    }
  }
  // printf("Result: %d\n", result);
  return result;
}
