// 11. Write a program that uses functions to perform the following operations
// on singly linked list
// a) Creation
// b) Insertion 1) Insertion at beginning 3)
// Insertion at specified position 3) Insertion at end
// c) Deletion 1) Deletion from the beginning 2) Deletion from the specified
// position 3) Deletion from the end d) Traversal. e) Exit
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
  int data;
  struct node *next;
} Node;
Node *createNode(int data) {
  Node *new = malloc(sizeof(Node));
  new->data = data;
  new->next = NULL;
  return new;
}
void traverseList(Node *node) {
  Node *temp;
  for (temp = node; temp != NULL; temp = temp->next) {
    printf("%d ", temp->data);
  }
  printf("\n");
}

void insertNode(int data, Node **head, int pos) {
  Node *new = createNode(data);
  Node *temp;
  if (pos == 0) {
    new->next = *head;
    *head = new;
    printf("Inserted %d at head.\n", data);
    return;
  }
  if (pos == -1) {
    for (temp = *head; temp->next != NULL; temp = temp->next)
      ;
    temp->next = new;
    printf("Inserted %d at end.\n", data);
    return;
  }
  temp = *head;
  for (int i = 0; i < pos - 1; i++) {
    temp = temp->next;
  }
  new->next = temp->next;
  temp->next = new;
  printf("Inserted %d at position %d.\n", data, pos);
}

void printNode(Node *node) { printf("%d", node->data); }

void deleteNode(Node **head, int pos) {
  if (pos == 0) {
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Deleted data at head.\n");
    return;
  }
  if (pos == -1) {
    Node *cursor = *head, *temp;
    for (cursor = *head; cursor->next->next != NULL; cursor = cursor->next)
      ;
    temp = cursor->next;
    cursor->next = NULL;
    free(temp);
    printf("Deleted data at end.\n");
    return;
  }
  Node *cursor = *head;
  for (int i = 0; i < pos - 1; i++) {
    cursor = cursor->next;
    if (cursor == NULL) {
      printf("Out of boundary.");
      exit(1);
    }
  }
  if (cursor->next == NULL) {
    printf("Out of boundary.");
    exit(1);
  }
  Node *temp = cursor->next;
  cursor->next = cursor->next->next;
  free(temp);
  printf("Deleted data at position: %d.\n", pos);
}

int main() {
  Node *list = createNode(12);
  // insert at head
  insertNode(20, &list, 0);
  // insert at end
  insertNode(30, &list, -1);
  // insert at pos 2
  insertNode(40, &list, 2);

  traverseList(list);
  // delete at second postion
  deleteNode(&list, 2);
  traverseList(list);
  // delete at head
  deleteNode(&list, 0);
  traverseList(list);
  deleteNode(&list, -1);
  traverseList(list);
}
