#include <stdio.h>

int main() {
  int i = 17;
  int f = fibonnaci(i);
  printf("Fibonnaci of %d is %d\n", i, f);

  return 0;
}

int fibonnaci(int i) {
  if (i == 0) {
    return 0;
  }
  else if (i == 1) {
    return 1;
  }

  return fibonnaci(i - 1) + fibonnaci(i - 2);
}
