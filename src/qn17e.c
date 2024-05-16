#include <stdio.h>
#include <stdlib.h>

void merge(int array[], int left, int mid, int right) {
  int left_half_size, right_half_size, left_pointer, right_pointer,
      original_pointer;
  left_half_size = mid - left + 1;
  right_half_size = right - mid;
  right_pointer = left_pointer = 0;

  int left_half[left_half_size], right_half[right_half_size];
  for (int i = 0; i < left_half_size; i++) {
    left_half[i] = array[left + i]; // left + max(i) = mid
  }
  for (int i = 0; i < right_half_size; i++) {
    right_half[i] = array[mid + 1 + i];
  }

  for (original_pointer = left;
       left_pointer < left_half_size && right_pointer < right_half_size;
       original_pointer++) {
    if (left_half[left_pointer] < right_half[right_pointer])
      array[original_pointer] = left_half[left_pointer++];
    else
      array[original_pointer] = right_half[right_pointer++];
  }

  while (left_pointer < left_half_size) {
    array[original_pointer++] = left_half[left_pointer++];
  }
  while (right_pointer < right_half_size) {
    array[original_pointer++] = right_half[right_pointer++];
  }
}

void mergesort(int array[], int left, int right) {
  if (left < right) { // this means sub array has more than one element

    /* not using  mid = (left + right) / 2 because
     * if (left + right) is more than what sizeof(int) can store then it will
     * overflow so left + (right - left)/2 is more safer as there is less chance
     * of overflow */

    int mid = left + (right - left) / 2;

    mergesort(array, left, mid);

    mergesort(array, mid + 1, right);

    merge(array, left, mid, right);
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
  mergesort(array, 0, length - 1);

  printf("Merge sorted array: ");
  print_array(array, length);
  printf("-------------Submitted by Sandesh Khadka---------\n");
}
