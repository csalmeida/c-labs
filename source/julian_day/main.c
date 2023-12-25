#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h> // Allows integer sizes to be specified.
#include <stdbool.h> // Allows the bool type to be used.

// Core functions:
void print_description();
uint16_t get_day();
uint16_t get_month();
uint16_t get_year();
uint64_t convert_to_jdn(uint16_t day, uint16_t month, uint16_t year);
void run_jdn_converter();

// Test related functions:
bool assert(bool predicate);
bool test(const char *name, bool passed);
void tests();

int main() {
  // Requests year as input and prints a result to the terminal:
  run_jdn_converter();

  // Running tests (optional): 
  tests();

  return EXIT_SUCCESS;
}

// Tell the user about the program:
void print_description() {
  printf("\n\n Gregorian Date to Julian Day Number Conversion 💫\n\n");
  printf("This utility receives a date in the Gregorian format and converts it to the Julian Day Number.\n");
  printf("The Julian Day Number is a continuous count of days since the beginning of the Julian calendar on January 1, 4713 BCE (Before Common Era). \n");
  printf("This algorithm won't validate a date before performing conversion, \n if a day is entered that does not exist it will throw unexpected results.\n");
}

// Prompt user to enter a day, once captured, it returns it.
// It only accepts a number as an input.
uint16_t get_day() {
    uint16_t max_day = 31;
    uint32_t user_number;

    // Loop until a valid integer is entered
    while (1) {
        printf("Please type in a day: ");

        // Check if the input is an integer
        // FIXME: Maybe atoi can be used here:
        if (scanf("%d", &user_number) == 1 && user_number <= max_day) {
            return (uint32_t)user_number; // Exit the loop if a valid integer is entered
        } 
          else if (user_number > max_day) {
            // Clear the input buffer in case of invalid input
            while (getchar() != '\n');
            printf("🛑 Invalid day. Please enter a day up to %d. \n", max_day);
          } else {
            // Clear the input buffer in case of invalid input
            while (getchar() != '\n');
            printf("🛑 Invalid day. Please enter a year as numbers e.g. 14.\n");
        }
    }
    return EXIT_SUCCESS;
}

// Prompt user to enter a month, once captured, it returns it.
// It only accepts a number as an input.
uint16_t get_month() {
    uint16_t max_month = 12;
    uint32_t user_number;

    // Loop until a valid integer is entered
    while (1) {
        printf("Please type in a month: ");

        // Check if the input is an integer
        // FIXME: Maybe atoi can be used here:
        if (scanf("%d", &user_number) == 1 && user_number <= max_month) {
            return (uint32_t)user_number; // Exit the loop if a valid integer is entered
        } 
          else if (user_number > max_month) {
            // Clear the input buffer in case of invalid input
            while (getchar() != '\n');
            printf("🛑 Invalid month. Please enter a month up to %d. \n", max_month);
          } else {
            // Clear the input buffer in case of invalid input
            while (getchar() != '\n');
            printf("🛑 Invalid month. Please enter a month as numbers e.g. 2.\n");
        }
    }
    return EXIT_SUCCESS;
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
        // FIXME: Maybe atoi can be used here:
        if (scanf("%d", &user_number) == 1 && user_number <= max_year) {
            return (uint32_t)user_number; // Exit the loop if a valid integer is entered
        } 
          else if (user_number >= max_year) {
            // Clear the input buffer in case of invalid input
            while (getchar() != '\n');
            printf("🛑 Invalid year. Please enter a year up to %d. \n", max_year);
          } else {
            // Clear the input buffer in case of invalid input
            while (getchar() != '\n');
            printf("🛑 Invalid year. Please enter a year as numbers e.g. 2000.\n");
        }
    }
    return EXIT_SUCCESS;
}

// Runs the following algorithm to calculate the Julian Number Day from a Gragorian date:
// JDN = (1461 × (Y + 4800 + (M − 14)/12))/4 +(367 × (M − 2 − 12 × ((M − 14)/12)))/12 − (3 × ((Y + 4900 + (M - 14)/12)/100))/4 + D − 32075
uint64_t convert_to_jdn(uint16_t day, uint16_t month, uint16_t year) {
  // Fail if any date inputs are 0:
  if (day == 0 || month == 0 || year == 0) {
    return EXIT_FAILURE;
  }

  // TODO: Need date validation.
  // No need to continue if the day is longer than the longest month:
  if (day > 31) {
    return EXIT_FAILURE;
  }

  // TODO: Need date validation.
  // No need to continue if the month is not one of the twelve months:
  if (month > 12) {
    return EXIT_FAILURE;
  }

  // Initial adjustments:
  uint16_t a = (14 - month) / 12;
  uint16_t b = year + 4800 - a;
  uint16_t c = month + 12 * a - 3;
  uint64_t e = (153 * c + 2) / 5;
  e = e + day - 1;

  // Running the algorithm:
  uint64_t jdn = b * 365 + (b / 4) - (b / 100) + (b / 400) + e - 32045;

  // FIXME: return JDN instead when we have it
  return jdn;
}

// Requests date (day, month and year) input and prints the resulting JDN to the terminal.
void run_jdn_converter() {
  print_description();

  // Capture a date from the user:
  uint16_t day = get_day();
  uint16_t month = get_month();
  uint16_t year = get_year();

  // TODO: Print result to the user:
  uint64_t jdn = convert_to_jdn(day, month, year);

  printf("The Julian Day Number for %d/%d/%d is: %d\n", day, month, year, jdn);
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

// Asserts that a value exits with a success status, useful to implement basic test functionality. 
// Similar to assert, the difference is that this function does not take a bool as an argument.
bool assert_exit_success(uint8_t status) {
  return status == EXIT_SUCCESS;
}

// Asserts that a value exits with a failure status.
// Similar to assert, the difference is that this function does not take a bool as an argument.
bool assert_exit_failure(uint8_t status) {
  return status == EXIT_FAILURE;
}

// Asserts if two unsigned integers are equal.
bool assert_uint_equals(uint64_t value, uint64_t result) {
  return value == result;
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

// Tests a dataset agains the convert_to_jdn function to confirm its accuracy.
void tests() {
  // Results should be:
  // - `1600-11-15` : `2305766`
  // - `1969-03-13` : `2440293`
  // - `1984-02-23` : `2445753`
  // - `1990-07-05` : `2448077`
  // - `2000-03-10`: `2451613`
  // - `2011-11-18`: `2455883`
  // - `2020-04-15` : `2458954`
  // - `2023-10-17` : `2460234`
  // - `2024-01-24` : `2460333`

  printf("\nRunning tests 🧪: \n\n");

    test("0 as day should fail", assert_exit_failure(convert_to_jdn(0, 12, 2023)));
    test("0 as month should fail", assert_exit_failure(convert_to_jdn(25, 0, 2023)));
    test("0 as year should fail", assert_exit_failure(convert_to_jdn(25,12,0)));

    test("day over 31 should fail", assert_exit_failure(convert_to_jdn(32, 12, 2023)));
    test("month over 12 should fail", assert_exit_failure(convert_to_jdn(25, 13, 2023)));

    test("15-11-1600 converts to JDN 2305766", assert_uint_equals(convert_to_jdn(15, 11, 1600), 2305766));
    test("13-03-1969 converts to JDN 2440293", assert_uint_equals(convert_to_jdn(13, 3, 1969), 2440293));
    test("23-02-1984 converts to JDN 2445753", assert_uint_equals(convert_to_jdn(23, 2, 1984), 2445753));
    test("05-07-1990 converts to JDN 2448077", assert_uint_equals(convert_to_jdn(5, 7, 1990), 2448077));
    test("10-03-2000 converts to JDN 2451613", assert_uint_equals(convert_to_jdn(10, 3, 2000), 2451613));
    test("18-11-2011 converts to JDN 2455883", assert_uint_equals(convert_to_jdn(18, 11, 2011), 2455883));
    test("15-04-2020 converts to JDN 2458954", assert_uint_equals(convert_to_jdn(15, 4, 2020), 2458954));
    test("17-10-2023 converts to JDN 2460234", assert_uint_equals(convert_to_jdn(17, 10, 2023), 2460234));
    test("24-01-2024 converts to JDN 2460333", assert_uint_equals(convert_to_jdn(24, 1, 2024), 2460333));

  printf("\nTest job finished. \n\n");
}

