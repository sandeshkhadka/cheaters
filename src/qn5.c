// 5. Write a recursive program to find the factorial value of given number.

#include <stdio.h>
int factorial(int num) {
  if (num == 1 || num == 0) {
    return 1;
  } else {
    return (num * factorial(num - 1));
  }
}

int main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);
  printf("Factorial of %d is %d.\n", num, factorial(num));
  printf("-------------Submitted by Sandesh Khadka---------\n");
  return 0;
}
