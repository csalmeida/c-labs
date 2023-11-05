#include <stdio.h>

int main(void) {
  char *s = "Hi!";

  printf("Printing string chars via index: \n");
  printf("%c\n", s[0]);
  printf("%c\n", s[1]);
  printf("%c\n", s[2]);

  // Because s is the address of a string, if we add to it will reveal the address of the next character.
  // We can then access the character with *.
  printf("Printing string chars via %s: \n", "%s");
  printf("%c\n", *s);
  printf("%c\n", *(s+1));
  printf("%c\n", *(s+2));
}