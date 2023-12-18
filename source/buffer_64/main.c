#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char buffer[64];
  printf("Enter an integer: ");
  fgets(buffer, 64, stdin);
  int val = atoi(buffer); // convert the string to an integer if (val % 2 == 1)
  val *= 2;
  val += 1;
  printf("%d\n", val);
}