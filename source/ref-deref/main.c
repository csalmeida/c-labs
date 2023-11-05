#include <stdio.h>

int main(void) {
  int n = 50;
  int *p = &n;

  printf("The address of n: %p\n", &n);
  printf("The value of n via pointer p: %i\n", *p);
}
