#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <strings.h>

void copy_with_strlcpy();
void copy_with_strcpy();

int main() {
  copy_with_strcpy();
  return EXIT_SUCCESS;
}

void copy_with_strlcpy() {
  // Temporary area to store copied string.
  char buffer[128];

  // Prompts for a string to copy:
  printf("Gimme a string: ");
  fgets(buffer, 128, stdin);

  // Stores length of the string (how many characters):
  size_t size = strlen(buffer) + 1; // add 1 for the null termination character! 
  
  // Array of characters stores copy:
  char copy[size];

  printf("The empty string array: %s", copy);

  // Copies the string using the strlcpy:
  // @FIXME: 
  // error: call to undeclared function 'strlcpy'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration] strlcpy(copy, buffer, size);
  // strlcpy(copy, buffer, size);
}

void copy_with_strcpy() {
  // Temporary area to store copied string.
  char buffer[128];

  // Prompts for a string to copy:
  printf("Gimme a string: ");
  fgets(buffer, 128, stdin);

  // Stores length of the string (how many characters):
  size_t size = strlen(buffer) + 1; // add 1 for the null termination character! 
  
  // Array of characters stores copy:
  char copy[size];
  
  // Copy string into another array:
  strcpy(copy, buffer);

  printf("Original string: %s", buffer);
  printf("Copied string: %s", copy);
}