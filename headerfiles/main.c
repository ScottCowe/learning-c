#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

int main() {
  stack_t *stak = (stack_t *) malloc(sizeof(stack_t));
  stak->head = (node_t *) malloc(sizeof(node_t));
  stak->head = NULL;

  push(stak, 1);
  push(stak, 2);

  printf("%d\n", pop(stak));
  printf("%d\n", pop(stak));

  free(stak);

  return 0;
}
