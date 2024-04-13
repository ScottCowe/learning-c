#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void push(stack_t *stak, int value) {
  node_t *newHead = (node_t *) malloc(sizeof(node_t));
  newHead->value = value;
  newHead->next = (node_t *) malloc(sizeof(node_t));
  newHead->next = stak->head;

  stak->head = newHead;
}

int pop(stack_t *stak) {
  if (stak->head == NULL) {
    return NULL;
  }

  int value = stak->head->value;
  node_t *oldHead = stak->head;
  node_t *newHead = stak->head->next;

  stak->head = newHead;
  free(oldHead);

  return value;
}

int peek(stack_t *stak) {
  if (stak->head == NULL) {
    return NULL;
  }

  int value = stak->head->value;

  return value;
}
