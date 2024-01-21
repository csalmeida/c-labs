#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void array_example();
void set_all_array_items_to_zero();
void accessing_array_example();
void accessing_array_by_bytes_example();


int main() {
  array_example();
  set_all_array_items_to_zero();
  accessing_array_example();
  accessing_array_by_bytes_example();

  return EXIT_SUCCESS;
}

void array_example() {
  uint8_t scores[100];
  scores[0] = 13;
  scores [99] = 42;
}

// Accessing an array using index syntax:
void accessing_array_example() {
  // Sets an array with a few values:
  uint8_t scores[5] = { 13, 22, 34, 45, 54 };
  size_t index = 0;
  
  // The sizeof operator gives the amount of storage, in bytes, 
  // required to store an object of the type of the operand. 
  // This operator allows you to avoid specifying machine-dependent
  // data sizes in your programs.
  size_t size_of_first_item = sizeof(int);

  printf("\n");
  printf("➡️  Accessing array by index\n");
  printf("Size of an int: %zu bytes\n", size_of_first_item);
  printf("First item in array: %d\n", scores[index]);
  printf("Last item in array: %d\n", scores[index + 4]);
  printf("\n");
}

// Accessing an array by adding bytes.
// Adding bytes makes the point shift through memory until it finds the correct element: 
void accessing_array_by_bytes_example() {
  // Sets an array with a few values:
  // Can't use uint8_t because it takes 1 byte, instead of the expected 4.
  int scores[5] = { 13, 22, 34, 45, 54 };
  size_t first_index = 0;
  size_t last_index = 4; 
  
  // The sizeof operator gives the amount of storage, in bytes, 
  // required to store an object of the type of the operand. 
  // This operator allows you to avoid specifying machine-dependent
  // data sizes in your programs.
  size_t size_of_item = sizeof(int);

  // Here we get the pointer of the scores array
  // and the size of the int type for the array value in bytes.
  // Multiplying the size by the index and adding it to the score pointer number returns the number of bytes to move to the target item.
  int* first_item = scores + first_index;
  int* last_item = scores + last_index;

  // Printing notes:
  printf("\n");
  printf("➡️  Accessing array by bytes\n");
  printf("Scores array pointer: %p \n", scores);
  printf("Size of an int: %zu bytes\n", size_of_item);
  printf("First item in array: %d\n", *first_item);
  printf("Last item in array: %d\n", *last_item);
  printf("\n");
}

void set_all_array_items_to_zero() {
  // A way of adding the uint8_t to an array but keeping the size of int to 4 bytes.
  uint8_t scores[100 * sizeof(int)];

  // The sizeof function retrieves the size of the array.
  // Then the memset function sets all the values in the array to 0.
  memset(scores, 0, sizeof(scores));

  // Printing how much space in memory it's taking:
  printf("\n");
  printf("➡️  Set 100 items to 0: %lu bytes \n", sizeof(scores));
  printf("\n");
}