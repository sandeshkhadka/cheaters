// 4. Write a program to convert Infix Expression into Prefix Expression.
#include <stdio.h>
#include <stdlib.h>
#define MAX_EXPRESSION_SIZE 50
#define MAX_STACK_SIZE 20
typedef char STACK_ITEM;
typedef struct {
  STACK_ITEM items[MAX_STACK_SIZE];
  STACK_ITEM top;
} Stack;

Stack *create_empty_stack() {
  Stack *stack = malloc(sizeof(Stack));
  stack->top = -1;
  return stack;
}

STACK_ITEM isFull_stack(Stack *stack) {
  if (stack->top == MAX_STACK_SIZE - 1) {
    return 1;
  } else {
    return 0;
  }
}

STACK_ITEM isEmpty_Stack(Stack *stack) {
  if (stack->top == -1) {
    return 1;
  } else {
    return 0;
  }
}

STACK_ITEM pop_stack(Stack *stack) {
  if (isEmpty_Stack(stack)) {
    exit(1);
  }
  return stack->items[stack->top--];
}

void push_stack(Stack *stack, STACK_ITEM item) {
  if (isFull_stack(stack)) {
    exit(1);
  }
  stack->items[++stack->top] = item;
}

STACK_ITEM peek_stack(Stack *stack) { return stack->items[stack->top]; }

void taverse_stack(Stack *stack, void (*callback)(STACK_ITEM)) {
  if (isEmpty_Stack(stack)) {
    return;
  }
  for (STACK_ITEM i = stack->top; i >= 0; i--) {
    callback(stack->items[stack->top]);
  }
}
int calculate_precedence(char c) {
  if (c == '+' || c == '-')
    return 0;
  if (c == '*' || c == '/')
    return 1;
  if (c == '^')
    return 3;
  return -1;
}
void handle_operator(char c, Stack *operator_stack,
                     STACK_ITEM prefix_expression[], int *i) {
  if (isEmpty_Stack(operator_stack)) {
    push_stack(operator_stack, c);
    return;
  }
  if (peek_stack(operator_stack) == ')') {
    push_stack(operator_stack, c);
    return;
  }
  if (c == ')') {
    push_stack(operator_stack, c);
    return;
  }

  if (c == '(') {
    char popped = pop_stack(operator_stack);
    while (popped != ')') {
      prefix_expression[*i++] = popped;
      printf("%d", *i);
      popped = pop_stack(operator_stack);
    }
    return;
  }
  int operator_precedence = calculate_precedence(c);
  int tos_precedence = calculate_precedence(peek_stack(operator_stack));
  if (operator_precedence > tos_precedence) {
    push_stack(operator_stack, c);
  } else if (operator_precedence <= tos_precedence) {
    if (c != '^') {
      push_stack(operator_stack, c);
      return;
    }
    prefix_expression[*i++] = pop_stack(operator_stack);
    handle_operator(c, operator_stack, prefix_expression, i);
  };
}
void reverse(STACK_ITEM expression[]) {
  STACK_ITEM c;
  Stack *expression_stack = create_empty_stack();
  for (int i = 0; i < MAX_STACK_SIZE; i++) {
    c = expression[i];
    if (c == '\n') {
      break;
    }
    push_stack(expression_stack, c);
  }
  int i = 0;
  while (isEmpty_Stack(expression_stack) != 1) {
    expression[i] = pop_stack(expression_stack);
    i++;
  }
  expression[i++] = '\n';
}
int main() {

  Stack *operator_stack = create_empty_stack();
  char expression[MAX_EXPRESSION_SIZE];
  char prefix_expression[MAX_EXPRESSION_SIZE];
  reverse(expression);
  char c;
  printf("Enter expression: ");
  for (int i = 0; i < MAX_EXPRESSION_SIZE; i++) {
    c = getchar();
    expression[i] = c;
    if (c == '\n')
      break;
  }
  printf("Prefix expression: ");
  int i;
  for (i = 0; i < MAX_EXPRESSION_SIZE; i++) {
    c = expression[i];
    if (c == '\n') {
      break;
    }
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
      prefix_expression[i] = c;
      continue;
    } else {
      handle_operator(c, operator_stack, prefix_expression, &i);
    }
  }
  while (isEmpty_Stack(operator_stack) != 1) {
    prefix_expression[i] = pop_stack(operator_stack);
    i++;
  }
  reverse(prefix_expression);

  for (i = 0; i < MAX_EXPRESSION_SIZE; i++) {
    if (prefix_expression[i] == '\n')
      break;
    printf("%c", prefix_expression[i]);
  }

  printf("\n");
  printf("-------------Submitted by Sandesh Khadka---------\n");
}
