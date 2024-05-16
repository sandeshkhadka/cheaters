// 9. Write a menu driven program to illustrate basic operations of Linear queue
//  using array implementation and pointer implementation.
//  a) Enqueue b) Dequeue c) Display all values d) Exit
#include <ncurses.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

typedef struct {
  Node *front, *rear;
} Queue;

void initQueue(Queue *q) {
  q->front = NULL;
  q->rear = NULL;
}

int isEmpty(Queue *q) { return q->front == NULL; }

void enqueue(Queue *q, int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = value;
  newNode->next = NULL;
  if (isEmpty(q)) {
    q->front = newNode;
  } else {
    q->rear->next = newNode;
  }
  q->rear = newNode;
  printw("Inserted %d\n", value);
}

void dequeue(Queue *q) {
  if (isEmpty(q)) {
    printw("Queue is empty!\n");
  } else {
    Node *temp = q->front;
    printw("Deleted %d\n", temp->data);
    q->front = q->front->next;
    if (q->front == NULL) {
      q->rear = NULL;
    }
    free(temp);
  }
}

void display(Queue *q) {
  if (isEmpty(q)) {
    printw("Queue is empty!\n");
  } else {
    Node *temp = q->front;
    while (temp) {
      printw("%d ", temp->data);
      temp = temp->next;
    }
    printw("\n");
  }
}

int main() {
  initscr();
  Queue q;
  initQueue(&q);

  int choice, value;

  while (1) {
    printw("-------------Submitted by Sandesh Khadka---------\n");
    printw("1. Enqueue\n2. Dequeue\n3. Display all values\n4. Exit\n");
    printw("Enter your choice: ");
    scanw("%d", &choice);
    switch (choice) {
    case 1:
      printw("Enter value to be inserted: ");
      scanw("%d", &value);
      enqueue(&q, value);
      break;
    case 2:
      dequeue(&q);
      break;
    case 3:
      display(&q);
      break;
    case 4:
      exit(0);
    default:
      printw("Invalid choice!\n");
    }
  }
  getch();

  return 0;
}
