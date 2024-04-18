#include <stdio.h>
#include <string.h>

int main(void) {
  char *s = "Hello";
  char *t = "Hello";

  // Compares references to pointers, not the contents of the string.
  if (s == t) {
    printf("Same\n");
  } else {
    printf("Different\n");
  }

  // Compares actual string.
  if (strcmp(s, t) == 0) {
    printf("Same\n");
  } else {
    printf("Different\n");
  }
}