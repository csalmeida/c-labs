#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Prompts for a number until it reaches the cutoff value.
// It allows that the last amount is past the cutoff value but it doesn't allow
// adding to it after that.
int main(void) {
  char buffer[64];
  uint32_t value = 0;
  uint32_t cutoff_value = 3000;
  // Request a value indefinitely:
  while(value <= cutoff_value) {
      printf("❄️ Current snowfall is: %u\n", value);
      printf("Please enter the additional amount of snowfall (Kg): ");
      fgets(buffer, 64, stdin);
    
      value = value + atoi(buffer);
  }

  printf("🏔️ Final snowfall amount is: %u \n", value);
}