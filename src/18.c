// 18. Write a program to implement Breadth First Search and Depth First Search in graph.

// Source Code
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10

// Queue structure for BFS
struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
};

// Function prototypes
struct Queue* createQueue();
void enqueue(struct Queue* q, int value);
int dequeue(struct Queue* q);
int isEmpty(struct Queue* q);

// Depth First Search
void dfs(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int visited[], int start, int vertices);

// Breadth First Search
void bfs(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int visited[], int start, int vertices);

int main() {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0};
    int vertices, edges, v1, v2;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (vertex1 vertex2): \n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &v1, &v2);
        adjMatrix[v1][v2] = 1;
        adjMatrix[v2][v1] = 1;
    }

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    // Mark all vertices as not visited
    int visited[MAX_VERTICES] = {0};

    printf("\nDepth First Search: ");
    dfs(adjMatrix, visited, startVertex, vertices);

    printf("\nBreadth First Search: ");
    bfs(adjMatrix, visited, startVertex, vertices);

       printf("\n Saroj Dhakal");


    return 0;
}

// Depth First Search
void dfs(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int visited[], int start, int vertices) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[start][i] == 1 && visited[i] == 0) {
            dfs(adjMatrix, visited, i, vertices);
        }
    }
}


// Breadth First Search
void bfs(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int visited[], int start, int vertices) {
    struct Queue* q = createQueue();

    visited[start] = 1;
    enqueue(q, start);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
}

// Queue implementation for BFS
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1) {
        printf("Queue is full.\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    return item;
}

int isEmpty(struct Queue* q) {
    return (q->front == -1 || q->front > q->rear);

}

