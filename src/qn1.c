#include <ncurses.h>
#include <stdlib.h>
#define MAX_ITEMS 10
typedef struct {
  int data[MAX_ITEMS];
  int tos;
} Stack;

Stack *create_stack() {
  Stack *stack = malloc(sizeof(Stack));
  stack->tos = -1;
  return stack;
}
int push_stack(Stack *stack, int value) {
  if (stack->tos >= MAX_ITEMS) {
    printw("Cannot push. Stack is full!");
    return -1;
  }
  stack->data[++stack->tos] = value;
  return stack->tos;
}

int pop_stack(Stack *stack) {
  if (stack->tos < 0) {
    printw("Cannot pop. Stack is empty!");
    return -1;
  }
  return stack->data[stack->tos--];
}

void traverse_stack(Stack *stack) {
  printw("-------------------Traversing Stack--------------------------------"
         "------------\n");
  for (int i = 0; i <= stack->tos; i++) {
    printw("%d. %d\n", i + 1, stack->data[i]);
  }
}

int main() {
  initscr();
  int choice = 0, value;
  Stack *stack = create_stack();
  printw("--------------MENU DIRIVEN PROGRAM FOR BASIC OPERTION OF "
         "STACK-----------------\n");
  printw("1.Push\n2.Pop\n3.Traverse\n4.Exit\n");
  while (choice != 4) {
    printw("Choice(1-4): ");
    scanw("%d", &choice);
    switch (choice) {
    case 1:
      printw("\nEnter a value: ");
      scanw("%d", &value);
      int index = push_stack(stack, value);
      if (index < 0)
        break;
      printw("%d inserted at index %d.\n", value, index);
      break;
    case 2:
      if (stack->tos < 0) {
        printw("Stack is empty\n");
        break;
      }
      value = pop_stack(stack);

      printw("Popped %d.\n", value);
      break;
    case 3:;
      traverse_stack(stack);
      break;
    default:
      exit(0);
      break;
    }
    printw("Press Enter to Continue!");
    getch();
    printw("-------------Submitted by Sandesh Khadka---------\n");
  }
  return 0;
}
