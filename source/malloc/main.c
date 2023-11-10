#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  char *source = "hello";
  char *target =  malloc(strlen(source) + 1);
  if (target == NULL) {
    return 1;
  }

  // Copy the string in source to target:
  strcpy(target, source);

  // Set the first character to be uppercase.
  if (strlen(target) > 0) {
    target[0] = toupper(target[0]);
  }

  printf("source: %s\n", source);
  printf("target: %s\n", target);

  // Frees allocated memory:
  free(target);

  return 0;
}