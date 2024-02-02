#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void storing_characters_individually();
void storing_characters_in_array();

int main() {
  storing_characters_individually();
  storing_characters_in_array();
  return EXIT_SUCCESS;
}

// A string is an array of characters.
// If they were stored in dividually they would look like the code below.
// We can then print them together, one after the other to form a sentence.
void storing_characters_individually() {
  char c1 = 'H';
  char c2 = 'I';
  char c3 = '!';
  
  printf("Printing characters:\n");
  printf("%c%c%c", c1,c2,c3);
  printf("\n\n");

  printf("Printing chars as ints:\n");
  printf("%i %i %i", c1,c2,c3);
  printf("\n\n");
}

void storing_characters_in_array() {
   char name[15] = {
     'T', 'h', 'e', 
     ' ', 'C', ' ', 
     'L', 'a', 'n', 'g', 'u', 'a', 'g', 'e', 
     '\0' 
    };

    // The amount of characters present in the string.
    // Does not include the null character but
    // includes \n and other special characters.
    size_t length = strlen(name);

    printf("%s\n", name);
    printf("String length is: %zu\n", length);
}