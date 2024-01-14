#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("How many scores to input? ");
  
  // Capture number of scores:
  char buffer[10];
  fgets(buffer, 10, stdin);

  // Convert scores to integer:
  int num_scores = atoi(buffer);

  // Create array with the chosen number of scores:
  int scores[num_scores];

  // Add scores to the array by prompting the user:
  for (int i = 0; i < num_scores; i++) {
    printf("Enter score %d: ", i+1);
    fgets(buffer, 10, stdin);
    scores[i] = atoi(buffer);
  }

  return EXIT_SUCCESS;
}