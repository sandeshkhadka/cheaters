#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50
typedef struct {
  int next_index;
  int *data;
} MinHeap;

void print_array(int *array, int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
void adjust_min_heap(MinHeap *heap) {
  int temp, parent;
  int cursor = heap->next_index - 1;
  if (heap->next_index < 2)
    return;
  while (cursor > 0) {
    parent = (cursor % 2 == 0) ? (cursor - 2) / 2 : (cursor - 1) / 2;
    if (heap->data[cursor] < heap->data[parent]) {
      temp = heap->data[cursor];
      heap->data[cursor] = heap->data[parent];
      heap->data[parent] = temp;
      cursor = parent;
    }
  }
}
MinHeap *create_min_heap(int *array, int length) {
  MinHeap *heap = malloc(sizeof(MinHeap *));
  heap->data = malloc(sizeof(int) * MAX_SIZE);
  heap->next_index = 0;
  for (int i = 0; i < length && i < MAX_SIZE; i++) {
    heap->data[heap->next_index++] = array[i];
    adjust_min_heap(heap);
  }
  return heap;
}

int pop_min_heap(MinHeap *heap) {
  int value = heap->data[0];
  int last = heap->data[heap->next_index - 1];
  int left, right, cursor, temp;
  heap->data[0] = last;
  heap->next_index--;

  for (cursor = 0, left = 1, right = 2; left < heap->next_index;
       left = 2 * cursor + 1, right = 2 * cursor + 2) {

    if (right > heap->next_index) {
      temp = heap->data[cursor];
      heap->data[cursor] = heap->data[left];
      heap->data[left] = temp;
      break;
    }
    if (heap->data[left] < heap->data[right]) {
      temp = heap->data[cursor];
      heap->data[cursor] = heap->data[left];
      heap->data[left] = temp;
      cursor = left;
    } else {
      temp = heap->data[cursor];
      heap->data[cursor] = heap->data[right];
      heap->data[right] = temp;
      cursor = right;
    }
  }
  return value;
}

void heap_sort(int *array, int length) {
  MinHeap *heap = create_min_heap(array, length);
  for (int i = 0; i < length; i++) {
    array[i] = pop_min_heap(heap);
  }
};

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
  heap_sort(array, length);

  printf("Heap sorted array: ");
  print_array(array, length);
  printf("-------------Submitted by Sandesh Khadka---------\n");
}
