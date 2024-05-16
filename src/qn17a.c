// 17. Write a program to enter n numbers and sort according to.
// a) Bubble sort
// b) Insertion sort
// c) Selection sort
// d) Quick sort
// e) Merge sort
// f) Heap sort
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int array[], int size) {
  int temp;
  for (int i = 1; i < size; i++) {
    for (int j = 0; j < size - i; j++) {
      if (array[j] > array[j + 1]) {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
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
  bubble_sort(array, length);

  printf("Bubble sorted array: ");
  print_array(array, length);
  printf("-------------Submitted by Sandesh Khadka---------\n");
}
