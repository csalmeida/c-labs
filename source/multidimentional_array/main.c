#include <stdio.h>
#include <stdlib.h>

int main() {
  char board[3][3] = {
    {'O', 'O', ' '}, 
    {'X', 'X', 'O'},
    {' ', 'O', 'X'}
  };

  printf("An element of a multidimentional array: %c\n", board[1][1]);

  return EXIT_SUCCESS;
}