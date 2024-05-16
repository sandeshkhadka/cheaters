// 7. Write a recursive program to find GCD of two integers.
#include <stdio.h>

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

int main() {
  int num1, num2;
  printf("Enter two numbers: ");
  scanf("%d %d", &num1, &num2);
  int g = gcd(num1, num2);
  printf("GCD: %d\n", g);
  printf("-------------Submitted by Sandesh Khadka---------\n");
  return 0;
}
