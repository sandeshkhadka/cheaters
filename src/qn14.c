//14. Write a program to implement linear search.
#include <stdio.h>
#define size 10
int main() {
  int array[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  int target;
  printf("Enter item to search: ");
  scanf("%d", &target);
  for (int i = 0; i < size; i++) {
    if (array[i] == target) {
      printf("Found at index: %d\n", i);
      return 0;
    }
  }
  printf("Could not found the target.\n");
  return 0;
}
