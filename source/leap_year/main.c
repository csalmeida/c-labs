#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h> // Allows integer sizes to be specified.
#include <stdbool.h> // Allows the bool type to be used.

// Core functions:
void print_description();
uint16_t get_year();
bool check_if_leap_year(uint16_t year);
void leap_year_checker();

// Test related functions:
bool assert(bool predicate);
bool test(const char *name, bool passed);
void tests();

int main() {
  // Requests year as input and prints a result to the terminal:
  leap_year_checker();

  // Running tests (optional): 
  tests();

  return EXIT_SUCCESS;
}

// Tell the user about the program:
void print_description() {
  printf("\n\n Leap Year Checker 💫\n\n");
  printf("This utility checks if the entered year is a leap year.\n");
  printf("A leap year means an added day in February, increasing it from 28 to 29 days.\n");
  printf("It takes into account a few compensation rules,\nincluding, every century and every 400 years adjustments. \n");
}

// Prompt user to enter a year, once captured, it returns it.
// It only accepts a number as an input.
uint16_t get_year() {
    uint16_t max_year = 9999;
    uint32_t user_number;

    // Loop until a valid integer is entered
    while (1) {
        printf("Please type in a year: ");

        // Check if the input is an integer
        if (scanf("%d", &user_number) == 1 && user_number <= max_year) {
            return (uint32_t)user_number; // Exit the loop if a valid integer is entered
        } 
          else if (user_number >= max_year) {
            // Clear the input buffer in case of invalid input
            while (getchar() != '\n');
            printf("🛑 Invalid year. Please enter a year up to 9999. \n");
          } else {
            // Clear the input buffer in case of invalid input
            while (getchar() != '\n');
            printf("🛑 Invalid year. Please enter a year as numbers e.g. 2000.\n");
        }
    }
    return EXIT_SUCCESS;
}

// Runs checks on a year and assets if it's a leap year.
bool check_if_leap_year(uint16_t year) {
  // Fail if the year is 0:
  if (year == 0) {
    return false;
  }

  // If the year is a multiple of 4, check if it can be a leap year:
  if (year % 4 == 0) {
    // Year is a multiple of 100 so it might be skipped:
    if (year % 100 == 0) {
      // If the year is a multiple of 400, should still be marked as a leap year.
      if (year % 400 == 0) {
        return true;
      }

      // This leap year is meant to be skipped:
      return false;
    }

    // Passed all other checks so can be marked as a leap year.
    return true;
  }

  return false;
}

// Requests year input and prints a result to the terminal.
void leap_year_checker() {
    print_description();

  uint16_t year = get_year();
  bool is_leap_year = check_if_leap_year(year);
  
  if (is_leap_year) {
    printf("%d is a leap year. 💫\n", year);
  } else {
    printf("%d is not a leap year.\n", year);
  }
}

// Asserts if a value is true, useful to implement basic test functionality.
// At the moment I believe the concern should be to assert it and not care about printing the result to the user.
bool assert(bool predicate) {
  return predicate == true;
}

// Asserts that a predicate is false.
bool assert_not(bool predicate) {
  return predicate == false;
}

// Takes a name for the test and the result.
bool test(const char *name, bool passed) {
    if (passed) {
      printf("Test %s - PASSED ✅\n", name);
    } else {
      printf("Test %s - FAILED 🛑\n", name);
    }

  // Returns result:
  return passed;
}

// Tests a few years against the is_leap_year function to confirm its accuracy.
void tests() {
  // Results should be:
  // - `1600` : `true`
  // - `1969` : `false`
  // - `1984` : `true`
  // - `1990` : `false`
  // - `2000`: `true`
  // - `2011`: `false`
  // - `2020` : `true`
  // - `2023` : `false`
  // - `2024` : `true`

  printf("\nRunning tests 🧪: \n\n");

    test("0 as leap year should fail", assert_not(check_if_leap_year(0)));
    test("1600 is a leap year", assert(check_if_leap_year(1600)));
    test("1969 is not a leap year", assert_not(check_if_leap_year(1969)));
    test("1984 is a leap year", assert(check_if_leap_year(1984)));
    test("1990 is not a leap year", assert_not(check_if_leap_year(1990)));
    test("2000 is a leap year", assert(check_if_leap_year(2000)));
    test("2011 is not a leap year", assert_not(check_if_leap_year(2011)));
    test("2020 is a leap year", assert(check_if_leap_year(2020)));
    test("2023 is not a leap year", assert_not(check_if_leap_year(2023)));
    test("2024 is a leap year", assert(check_if_leap_year(2024)));

  printf("\nTest job finished. \n\n");
}

