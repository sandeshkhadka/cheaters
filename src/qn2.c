#include <ncurses.h>
#include <stdlib.h>
#define MAX_ITEMS 10
struct node {
  int data;
  struct node *next;
};
typedef struct {
  struct node *tos;
} Stack;
struct node *create_item(int value) {
  struct node *n = malloc(sizeof(struct node));
  n->data = value;
  n->next = NULL;
  return n;
}
Stack *create_stack() {
  Stack *stack = malloc(sizeof(Stack));
  stack->tos = NULL;
  return stack;
}
void push_stack(Stack *stack, int value) {
  struct node *temp = create_item(value);
  temp->next = stack->tos;
  stack->tos = temp;
}

int pop_stack(Stack *stack) {
  struct node *temp;
  int value = stack->tos->data;
  temp = stack->tos;
  stack->tos = stack->tos->next;
  free(temp);
  return value;
}

void traverse_stack(Stack *stack) {
  printw("-------------------Traversing Stack--------------------------------"
         "------------\n");
  struct node *temp;
  temp = stack->tos;
  while (temp != NULL) {
    printw("%d\t", temp->data);
    temp = temp->next;
  }
  printw("\n");
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
      push_stack(stack, value);
      printw("Inserted %d.\n", value);
      break;
    case 2:
      if (stack->tos == NULL) {
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
