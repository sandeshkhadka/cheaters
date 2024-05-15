#include <stdio.h>
#define size 10
void insertionsort(int array[], int length) {
  for (int k = 1; k < length; k++) {
    int current = array[k];
    int i;
    for (i = k - 1; i >= 0 && array[i] > current; i--) {
      array[i + 1] = array[i];
    }
    array[i + 1] = current;
  }
}
int main() {
  int array[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  int target;
  insertionsort(array, size);
  printf("Enter item to search: ");
  scanf("%d", &target);
  int l = 0, r = size - 1, mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (target == array[mid]) {
      printf("Found!\n");
      return 0;
    } else if (target > array[mid]) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  printf("Could not find the target.\n");
  return 0;
}
