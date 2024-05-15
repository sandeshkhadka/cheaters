#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front, *rear;
} Queue;

void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

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
    printf("Inserted %d\n", value);
}

void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        Node *temp = q->front;
        printf("Deleted %d\n", temp->data);
        q->front = q->front->next;
        if (q->front == NULL) {
            q->rear = NULL;
        }
        free(temp);
    }
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        Node *temp = q->front;
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    initQueue(&q);

    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display all values\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to be inserted: ");
                scanf("%d", &value);
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
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
