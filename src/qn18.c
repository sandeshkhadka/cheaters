// 18. Write a program to implement Breadth First Search and Depth First Search
// in graph.

#include <stdio.h>
#include <stdlib.h>
typedef struct n {
  int data;
  struct n *next;
} Node;
typedef struct {
  int numVertices;
  Node **adjLists;
  int *visited;
} Graph;
Node *create_node(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}
Graph *create_graph(int numVertices) {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->numVertices = numVertices;
  graph->adjLists = (Node **)malloc(numVertices * sizeof(Node *));
  graph->visited = (int *)malloc(numVertices * sizeof(int));
  for (int i = 0; i < numVertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}
void add_edge(Graph *graph, int src, int dest) {
  Node *newNode = create_node(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;
  newNode = create_node(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}
void bfs(Graph *graph, int startVertex) {
  int queue[graph->numVertices];
  int front = 0, rear = 0;
  graph->visited[startVertex] = 1;
  queue[rear++] = startVertex;
  while (front < rear) {
    int currentVertex = queue[front++];
    printf("%d ", currentVertex);
    Node *temp = graph->adjLists[currentVertex];
    while (temp != NULL) {
      int adjVertex = temp->data;
      if (!graph->visited[adjVertex]) {
        graph->visited[adjVertex] = 1;
        queue[rear++] = adjVertex;
      }
      temp = temp->next;
    }
  }
}
void dfs(Graph *graph, int vertex) {
  graph->visited[vertex] = 1;
  printf("%d ", vertex);
  Node *temp = graph->adjLists[vertex];
  while (temp != NULL) {
    int adjVertex = temp->data;
    if (!graph->visited[adjVertex]) {
      dfs(graph, adjVertex);
    }
    temp = temp->next;
  }
}
int main() {
  int numVertices = 6;
  Graph *graph = create_graph(numVertices);
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 0, 3);
  add_edge(graph, 6, 4);
  add_edge(graph, 4, 2);
  add_edge(graph, 2, 5);
  add_edge(graph, 2, 1);
  add_edge(graph, 1, 5);
  printf("Breadth First Search (BFS) starting from vertex 0: ");
  bfs(graph, 0);
  printf("\n");
  for (int i = 0; i < numVertices; i++) {
    graph->visited[i] = 0;
  }
  printf("Depth First Search (DFS) starting from vertex 0: ");
  dfs(graph, 0);
  printf("\n");
  printf("-------------Submitted by Sandesh Khadka---------\n");
  return 0;
}
