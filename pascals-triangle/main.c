#include <stdio.h>
#include <stdlib.h>

int main() {
  int rows = 10;

  char **ptriangle = (char **) malloc(rows * sizeof(char *));

  // Note that the number of cols in each row is equal to the row number
  for (int i = 0; i < rows; i++) {
    ptriangle[i] = (char *) malloc(i * sizeof(char *));

    for (int j = 0; j < i; j++) {
      if (j == 0 || j == i-1) {
        ptriangle[i][j] = 1;
      }
      else {
        ptriangle[i][j] = ptriangle[i-1][j-1] + ptriangle[i-1][j];
      }

      printf("%d\t", ptriangle[i][j]);
    }

    printf("\n");
  }

  for (int i = 0; i < rows; i++) {
    free(ptriangle[i]);
  }

  free(ptriangle);

  return 0; 
}
