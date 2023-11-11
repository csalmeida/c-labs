#include <stdio.h>
#include <stdlib.h>

int spacer() {
   printf("\n"); 
   return EXIT_SUCCESS;
}

int main(void) {
  spacer();
  
  char letter = 'z';
  printf("Char: %c\n", letter); // Prints the actual character.
  printf("Number representation: %d\n", letter); // The number it represents.
  printf("Address in memory: %p\n", &letter); // The number it represents.

  spacer();

  int char_num  = 122;
  printf("Char num: %d is (%c) \n", char_num, char_num);

  spacer();

  int last_printable_char  = 127;
  printf("Last printable character: %d is (%c) \n", last_printable_char, last_printable_char);

  spacer();

  int out_of_reach_char  = 50081;
  printf("Out of reach character: %d is (%c) but should be (á) \n", out_of_reach_char, out_of_reach_char);

  spacer();
  return 0;
}