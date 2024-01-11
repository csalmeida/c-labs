//Say that you want to simulate rolling a die (singular of dice) a fixed number of times and to compute and print the average value for the die rolls. What control structure would work best for this problem, and why?
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

uint8_t roll_die(); 
double roll_die_average(uint8_t times);

int main() {
  // Generates a seed for the random number.
  srand(time(NULL));

  uint8_t times = 232;
  double median = roll_die_average(232);
  printf("🎲 Rolled %d times\n🎯 Roll median: %f\n", times, median);

  return EXIT_SUCCESS;
}

uint8_t roll_die() {
  // The die roll can yield a number from 1 to 6:
  uint8_t range_min = 1;
  uint8_t range_max = 6 + 1; // Adds 1 to guarantee that 6 be yielded.

  // Because rand() will return any from 0 to 32767.
  // It's limited to the die's range using the following formula:
  uint8_t random_num = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
  return random_num;
}

// Takes an empty rolls array and the amount of rolls.
// Each time it rolls it will add an entry to the array.
// The amount of times depends on the size of the array.
double roll_die_average(uint8_t times) {
  int64_t sum = 0;

  // Add all the rolls up:
  for (size_t index = 0; index < times; index++)
  {
    sum = roll_die();
  }

  double median = (double) sum / (double) times;
  return median;
}