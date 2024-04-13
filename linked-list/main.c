#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next;
} node_t;

// Adds item to end of list
void push(node_t *head, int val) {
  node_t *current = head;

  while (current->next != NULL) {
    current = current->next;
  }

  current->next = (node_t *) malloc(sizeof(node_t));
  current->next->val = val;
  current->next->next = NULL; 
}

// Removes and returns value of item from end of list 
int pop(node_t *head) {
  if (head->next == NULL) {
    int val = head->val;
    free(head);
    return val;
  }

  node_t *current = head;
  
  while (current->next->next != NULL) {
    current = current->next;
  }

  int val = current->next->val;
  free(current->next);
  current->next = NULL;

  return val;
}

int main() {
  node_t *head = NULL;
  head = (node_t *) malloc(sizeof(node_t));

  if (head == NULL) {
    return 1;
  }

  head->val = 1;
  head->next = NULL;

  push(head, 2);

  printf("%d\n", pop(head));
  printf("%d\n", pop(head));

  return 0;
}
