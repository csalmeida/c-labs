#include <stdio.h>
#include <string.h>

int main(void) {
  char *s = "Hello";
  char *t = "Hello";

  if (s == t) {
    printf("Same\n");
  } else {
    printf("Different\n");
  }

  if (strcmp(s, t) == 0) {
    printf("Same\n");
  } else {
    printf("Different\n");
  }
}