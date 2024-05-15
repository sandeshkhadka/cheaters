#include <stdio.h>
#include <stdlib.h>

void quick_sort_partitioner(int array[], int lb, int ub, int *pj) {
  int left_cursor, right_cursor, pivot, temp;
  left_cursor = lb;
  right_cursor = ub;
  pivot = array[lb];
  while (left_cursor < right_cursor) {
    while (left_cursor < ub && array[left_cursor] <= pivot) {
      left_cursor++;
    }
    while (right_cursor > lb && array[right_cursor] > pivot) {
      right_cursor--;
    }
    if (left_cursor < right_cursor) {
      temp = array[left_cursor];
      array[left_cursor] = array[right_cursor];
      array[right_cursor] = temp;
    }
  }
  array[lb] = array[right_cursor];
  array[right_cursor] = pivot;
  *pj = right_cursor;
}

void quick_sort(int array[], int lb, int ub) {
  if (lb >= ub)
    return;
  int j;
  quick_sort_partitioner(array, lb, ub, &j);
  quick_sort(array, lb, j - 1);
  quick_sort(array, j + 1, ub);
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
  quick_sort(array, 0, length - 1);

  printf("Quick sorted array: ");
  print_array(array, length);
  printf("-------------Submitted by Sandesh Khadka---------\n");
}
