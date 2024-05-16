#include <stdio.h>
#include <stdlib.h>

void insertionsort(int array[], int size) {
  for (int k = 1; k < size; k++) {
    int current = array[k];
    int i;
    for (i = k - 1; i >= 0 && array[i] > current; i--) {
      array[i + 1] = array[i];
    }
    array[i + 1] = current;
  }
}


void print_array(int *array, int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
int main() {
  int length, *array;
  printf("Enter length of array: ");
  scanf("%d", &length);
  array = malloc(length * sizeof(int));
  printf("Enter elements: ");
  for (int i = 0; i < length; i++) {
    scanf("%d", &array[i]);
  }
  printf("Input array: ");
  print_array(array, length);
  insertionsort(array, length);

  printf("Insertion sorted array: ");
  print_array(array, length);
  printf("-------------Submitted by Sandesh Khadka---------\n");
}
