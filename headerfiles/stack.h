typedef struct node {
  int value;
  struct node *next;
} node_t;

typedef struct stack {
  node_t *head;
} stack_t;

void push(stack_t *stak, int value);

int pop(stack_t *stak);

int peek(stack_t *stak);
