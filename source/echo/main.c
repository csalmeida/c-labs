#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>

int spacer() {
   printf("\n"); 
   return EXIT_SUCCESS;
}

int text_prompt() {
    // Defines a string 64 characters long:
    char string[64];

    // Awaits user input for a string from standard input.
    printf("Type in some text:");
    fgets(string, 64, stdin);
    
    printf("You text is: %s\n", string);

    spacer();

    return EXIT_SUCCESS;
}

int char_to_upper_prompt() {
    int character = 0;
    printf("Type a single character: ");
    while (character != EOF) {
        character = getchar();
        int character_is_not_empty = character != 0 && character != 10;
        if (character_is_not_empty) {
          printf("Your char is %c\n\n", toupper(character));
          printf("Type another:");
        }
    }

    return EXIT_SUCCESS;
}

int dog_years() {
    // Defines a string 64 characters long:
    char string[64];

    printf("How old are you?");
    fgets(string, 64, stdin);
    
    int age = atoi(string) * 7;

    printf("🐶 Your age in dog years is: %d\n", age);
    return EXIT_SUCCESS; 
}

int main(void) {
  text_prompt();
  char_to_upper_prompt();
  dog_years();

  return EXIT_SUCCESS; 
}