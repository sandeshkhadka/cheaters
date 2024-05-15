#include <stdio.h>
#include <stdlib.h>

void selectionsort(int array[], int size) {
  for (int i = 0; i < size; i++) {
    int min = array[i];
    int index = i;
    for (int j = i + 1; j < size; j++) {
      if (array[j] < min) {
        min = array[j];
        index = j;
      }
    }
    array[index] = array[i];
    array[i] = min;
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
  selectionsort(array, length);

  printf("Selection sorted array: ");
  print_array(array, length);
  printf("-------------Submitted by Sandesh Khadka---------\n");
}
