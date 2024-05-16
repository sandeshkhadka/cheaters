// 19. Write a program to implement Kruskal’s algorithm.
#include <stdio.h>
#define MAX 30

typedef struct {
  int u, v, w;
} Edge;

typedef struct {
  Edge data[MAX];
  int n;
} EdgeList;

EdgeList elist;

int graph[MAX][MAX], n;

EdgeList spanlist;

void kruskal_algorithm();

int find(int belongs[], int vertexno);
void union_(int belongs[], int c1, int c2);
void sort();
void print();

void kruskal_algorithm() {
  int belongs[MAX], i, j, cno1, cno2;
  elist.n = 0;
  for (i = 1; i < n; i++)
    for (j = 0; j < i; j++) {
      if (graph[i][j] != 0) {
        elist.data[elist.n].u = i;
        elist.data[elist.n].v = j;
        elist.data[elist.n].w = graph[i][j];
        elist.n++;
      }
    }
  sort();
  for (i = 0; i < n; i++)
    belongs[i] = i;
  spanlist.n = 0;
  for (i = 0; i < elist.n; i++) {
    cno1 = find(belongs, elist.data[i].u);
    cno2 = find(belongs, elist.data[i].v);
    if (cno1 != cno2) {
      spanlist.data[spanlist.n] = elist.data[i];
      spanlist.n = spanlist.n + 1;
      union_(belongs, cno1, cno2);
    }
  }
}
int find(int belongs[], int vertexno) { return (belongs[vertexno]); }
void union_(int belongs[], int c1, int c2) {
  int i;
  for (i = 0; i < n; i++)
    if (belongs[i] == c2)
      belongs[i] = c1;
}
void sort() {
  int i, j;
  Edge temp;
  for (i = 1; i < elist.n; i++)
    for (j = 0; j < elist.n - 1; j++)
      if (elist.data[j].w > elist.data[j + 1].w) {
        temp = elist.data[j];
        elist.data[j] = elist.data[j + 1];
        elist.data[j + 1] = temp;
      }
}
void print() {
  int i, cost = 0;
  for (i = 0; i < spanlist.n; i++) {
    printf("%d ---- %d : %d\n", spanlist.data[i].u, spanlist.data[i].v,
           spanlist.data[i].w);
    cost = cost + spanlist.data[i].w;
  }
  printf("\nSpanning tree cost: %d", cost);
}
int main() {
  int i, j, total_cost;
  n = 6;
  int from_zero[7] = {0, 4, 4, 0, 0, 0, 0};
  int from_one[7] = {4, 0, 2, 0, 0, 0, 0};
  int from_two[7] = {4, 2, 0, 3, 4, 0, 0};
  int from_three[7] = {0, 0, 3, 0, 3, 0, 0};
  int from_four[7] = {0, 0, 4, 3, 0, 0, 0};
  int from_five[7] = {0, 0, 2, 0, 3, 0, 0};
  for (i = 0; i < 7; i++) {
    graph[0][i] = from_zero[i];
  }
  for (i = 0; i < 7; i++) {
    graph[0][i] = from_zero[i];
  }
  for (i = 0; i < 7; i++) {
    graph[1][i] = from_one[i];
  }
  for (i = 0; i < 7; i++) {
    graph[2][i] = from_two[i];
  }
  for (i = 0; i < 7; i++) {
    graph[3][i] = from_three[i];
  }
  for (i = 0; i < 7; i++) {
    graph[4][i] = from_four[i];
  }
  for (i = 0; i < 7; i++) {
    graph[5][i] = from_five[i];
  }

  kruskal_algorithm();

  print();
  printf("\n-------------Submitted by Sandesh Khadka---------\n");

  return 0;
}
