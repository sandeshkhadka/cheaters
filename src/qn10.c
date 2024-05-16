// 10. Write a menu driven program to illustrate basic operations of circular
// queue having following menu:
//  a) Enqueue b) Dequeue c) Traverse d) Exit
#include <ncurses.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct {
  Node *front, *rear;
} CircularQueue;

void initQueue(CircularQueue *q) { q->front = q->rear = NULL; }

int isEmpty(CircularQueue *q) { return q->front == NULL; }

void enqueue(CircularQueue *q, int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = value;
  if (isEmpty(q)) {
    q->front = newNode;
  } else {
    q->rear->next = newNode;
  }
  q->rear = newNode;
  q->rear->next = q->front; // Making it circular
  printw("Inserted %d\n", value);
}

void dequeue(CircularQueue *q) {
  if (isEmpty(q)) {
    printw("Queue is empty!\n");
  } else {
    Node *temp = q->front;
    if (q->front == q->rear) {
      q->front = q->rear = NULL;
    } else {
      q->front = q->front->next;
      q->rear->next = q->front;
    }
    printw("Deleted %d\n", temp->data);
    free(temp);
  }
}

void traverse(CircularQueue *q) {
  if (isEmpty(q)) {
    printw("Queue is empty!\n");
  } else {
    Node *temp = q->front;
    do {
      printw("%d ", temp->data);
      temp = temp->next;
    } while (temp != q->front);
    printw("\n");
  }
}

int main() {
  initscr();
  CircularQueue q;
  initQueue(&q);

  int choice, value;

  while (1) {
    printw("-------------Submitted by Sandesh Khadka---------\n");
    printw("1. Enqueue\n2. Dequeue\n3. Traverse\n4. Exit\n");
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
      traverse(&q);
      break;
    case 4:
      exit(0);
    default:
      printw("Invalid choice!\n");
    }
  }
  return 0;
}
