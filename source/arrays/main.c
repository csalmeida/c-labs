#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void array_example();
void set_all_array_items_to_zero();

int main() {
  array_example();
  set_all_array_items_to_zero();

  return EXIT_SUCCESS;
}

void array_example() {
  uint8_t scores[100];
  scores[0] = 13;
  scores [99] = 42;
}

void set_all_array_items_to_zero() {
  uint8_t scores[100];
  // The sizeof function retrieves the size of the array.
  // Then the memset function sets all the values in the array to 0.
  memset(scores, 0, sizeof(scores));
}