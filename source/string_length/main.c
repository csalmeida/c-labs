#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // Allows integer sizes to be specified.

/**
 * Calculates the length of a string by finding the NUL character.
*/
uint64_t string_len(char string[]) {
  uint64_t length = 0;

  // Adds to length until it finds the NUL character in the array:
  while (string[length] != '\0')
  {
    length++;
  }
  
  return length;
}

int main(void) {
  char text[] = "Hello, World";
  uint64_t length = string_len(text);
  printf("String is %lu characters long.\n", length);

  return EXIT_SUCCESS;
}