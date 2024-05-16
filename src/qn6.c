// 6. Write a recursive program to find a Fibonacci sequence.
#include <stdio.h>

int fibonacci(int num) {
  if (num == 1 || num == 0) {
    return 1;
  } else {
    return fibonacci(num - 1) + fibonacci(num - 2);
  }
}

int main() {
  int n;
  printf("Enter length: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    printf("%d  ", fibonacci(i));
  }
  printf("\n");
  printf("-------------Submitted by Sandesh Khadka---------\n");
}
