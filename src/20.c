// 20. Write a program to implement Dijkastra’s algorithm.

// Source Code
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 20

// Function prototypes
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int start, int vertices);

int main() {
    int vertices, start;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the weighted adjacency matrix of the graph:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    dijkstra(graph, start, vertices);
    printf("\n Saroj Dhakal");
    return 0;
}

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int visited[], int vertices) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < vertices; v++) 
{
       if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the shortest path from source to j
void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        return;
    }
    printPath(parent, parent[j]);
    printf("%d ", j);
}

// Function to print the constructed distance array
void printSolution(int dist[], int parent[], int start, int vertices) {
    printf("Vertex\tDistance\tPath\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d -> %d\t%d\t\t%d ", start, i, dist[i], start);
        printPath(parent, i);
        printf("\n");
    }
}

// Dijkstra's algorithm
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int start, int vertices) {
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES];
    int parent[MAX_VERTICES];

    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }
 // Distance of source vertex from itself is always 0
    dist[start] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < vertices - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        // u is always equal to start in the first iteration.
        int u = minDistance(dist, visited, vertices);

        // Mark the picked vertex as visited
        visited[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }       printSolution(dist, parent, start, vertices);}

