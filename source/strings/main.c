#include <stdio.h>
#include <stdlib.h>

void storing_characters_individually();

int main() {
  storing_characters_individually();
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