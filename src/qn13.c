// 13. Write a program to Implement binary tree and traverse tree with user’s
// choice (Inorder, Preorder, Postorder).

#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node *createNode(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (newNode == NULL) {
    printf("Memory allocation failed!\n");
    exit(1);
  }
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

struct Node *insert(struct Node *node, int data) {
  if (node == NULL) {
    return createNode(data);
  }

  if (data < node->data) {
    node->left = insert(node->left, data);
  } else if (data > node->data) {
    node->right = insert(node->right, data);
  }

  return node;
}

void inorder(struct Node *node) {
  if (node != NULL) {
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
  }
}

void preorder(struct Node *node) {
  if (node != NULL) {
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
  }
}

void postorder(struct Node *node) {
  if (node != NULL) {
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
  }
}

int getChoice() {
  int choice;
  printf("\nEnter your choice of traversal:\n");
  printf("1. Inorder\n");
  printf("2. Preorder\n");
  printf("3. Postorder\n");
  printf("Enter your choice (1/2/3): ");
  scanf("%d", &choice);
  return choice;
}

int main() {
  struct Node *root = NULL;

  int data, choice, n;
  printf("Enter no of data: ");
  scanf("%d", &n);
  printf("Enter data: ");
  for (int i = 0; i < n; i++) {

    scanf("%d", &data);
    root = insert(root, data);
  }

  // Traverse the tree based on user's choice
  while (1) {
    choice = getChoice();
    switch (choice) {
    case 1:
      printf("\nInorder traversal: ");
      inorder(root);
      break;
    case 2:
      printf("\nPreorder traversal: ");
      preorder(root);
      break;
    case 3:
      printf("\nPostorder traversal: ");
      postorder(root);
      break;
    default:
      printf("Invalid choice!\n");
    }
    printf("\nDo you want to perform another traversal (y/n)? ");
    char ch;
    scanf(" %c", &ch); // Read the space before the character
    if (ch != 'y' && ch != 'Y') {
      break;
    }
  }

  return 0;
}
