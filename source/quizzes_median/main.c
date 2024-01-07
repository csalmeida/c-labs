#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
  uint16_t quizzes_scores[10] = { 518, 37, 64, 93, 103, 684, 285, 642, 1999, 3930 };
  
  // How long the array is.
  uint8_t count = 10;

  // Collect the sum of all scores.
  uint32_t sum = 0; 
  for (size_t index = 0; index < count; index++) {
    sum = sum + quizzes_scores[index];
  }

  // Get the mean by dividing it by the number of scores.
  double mean = (double) sum / count; 
  
  printf("There were %d quizzes, with a mean score of %.1f\n", count, mean);

  return EXIT_SUCCESS;
}