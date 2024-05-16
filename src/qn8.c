// 8. Write a recursive program to implement TOH problem. (Show the output for 3
// disks)
#include <stdio.h>

void tower(int n, char from, char to, char aux) {
  if (n == 1) {
    printf("Move ring %d from peg %c to peg %c.\n", n, from, to);
    return;
  }
  tower(n - 1, from, aux, to);
  printf("Move ring %d from peg %c to peg %c.\n", n, from, to);
  tower(n - 1, aux, to, from);
}

int main() {
  int n;
  printf("Enter no of rings: ");
  scanf("%d", &n);
  tower(n, 'A', 'C', 'B');
  printf("-------------Submitted by Sandesh Khadka---------\n");
  return 0;
}
