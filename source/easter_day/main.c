#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h> // Allows integer sizes to be specified.
#include <stdbool.h> // Allows the bool type to be used.

void print_description();
void run_easter_finder();
void get_gregorian_easter_date(uint16_t *date, uint16_t year);
uint16_t get_year();

// Test related functions:
bool test_get_gregorian_easter_date(uint16_t expected_day, uint16_t expected_month, uint16_t year);
bool test_get_gauss_easter_date(uint16_t expected_day, uint16_t expected_month, uint16_t year);
bool test(const char *name, bool passed);
void tests();

int main() {
  // Requests year as input and prints a result to the terminal:
  // run_easter_finder();

  // Running tests (optional): 
  tests();

  return EXIT_SUCCESS;
}

// Tell the user about the program:
void print_description() {
  printf("\n\n Next Easter Day Finder 🐰\n\n");
  printf("This a program asks for a year value and computes and prints the month and day of Easter in that year.\n");
  printf("This algorithm won't validate a date before computing, \n if a day is entered that does not exist it will throw unexpected results.\n");
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

// As a moveable feast, the date of Easter is determined in each year through a calculation known as computus (Latin for 'computation').
// Easter is celebrated on the first Sunday after the Paschal full moon, which is the first full moon of Spring, on or after 21 March (a fixed approximation of the March equinox).
// Uses the Anonymous algorithm submitted by a "New York correspondent" to the journal Nature in 1876.
// The date parameter should be an array that can store 3 integers. A day, a month and a year, in that particular order.
// The caller of the function should define it like so:
// uint16_t date[3];
// get_gregorian_easter_date(date, 1876);
void get_gregorian_easter_date(uint16_t *date, uint16_t year) {
  // Anonymous Easter Algorithm:
  uint16_t a = year % 19;
  uint16_t b = year / 100;
  uint16_t c = year % 100;
  uint16_t d = b / 4;
  uint16_t e = b % 4;
  uint16_t f = (b + 8) / 25;
  uint16_t g = (b - f + 1) / 3;
  uint16_t h = (19 * a + b - d - g + 15) %  30;
  uint16_t i = c / 4;
  uint16_t k = c % 4;
  uint16_t l = (32 + 2 * e + 2 * i - h - k) % 7;
  uint16_t m = (a + 11 * h + 22 * l) / 451;
  uint16_t n = (h + l - (7 * m) + 114) / 31;
  uint16_t o = (h + l - 7 * m + 114) % 31;

  uint16_t month = n;
  uint16_t day = o + 1;
  
  // Assigns date to array:
  date[0] = day;
  date[1] = month;
  date[2] = year;
}

// Retrieves the gregorian (Solar) date for Easter for a given year using 
// Carl Friedrich Gauss' Easter algorithm.
// Using the Gauss's Easter algorithm for years prior to 1583 is historically pointless since the Gregorian calendar was not utilised for determining Easter before that year. 
// Using the algorithm far into the future is questionable, since we know nothing about how different churches will define Easter far ahead. Easter calculations are based on agreements and conventions, not on the actual celestial movements nor on indisputable facts of history. 
// The date parameter should be an array that can store 3 integers. A day, a month and a year, in that particular order.
// The caller of the function should define it like so:
// uint16_t date[3];
// get_gauss_easter_date(date, 1876);
void get_gauss_easter_date(uint16_t *date, uint16_t year) {
  uint16_t a = year % 19; // Year's position in the 19-year lunar phase cycle. The moon's movement relative to Earth repeats every 19 calendar years.
  uint16_t b = year % 4;
  uint16_t c = year % 7;
  uint16_t k = year / 100;
  uint16_t p = (13 + 8 * k) / 25;
  uint16_t q = k / 4;
  uint16_t M = (15 - p + k - q) % 30;
  uint16_t N = (4 + k - q) % 7;
  uint16_t d = (19 * a + M) % 30; //  The number of days (counting from 22 March) to the day after the full moon.
  uint16_t e = (2 * b + 4 * c + 6 * d + N) % 7; //  The additional offset days that must be added to the date offset d to make it arrive at a Sunday.

  int16_t march_easter_day = 22 + d + e;
  int16_t april_easter_day = d + e - 9;

  // Final date will be stored here after some considerations:
  uint16_t month;
  uint16_t day;

  // Assumes that Easter is in March to begin with:
  month = 3;
  day = march_easter_day;

  // Easter Sunday is going to be March (22 + D + E). If this number comes out to be greater than 31, then it moves to April.
  if (march_easter_day > 31) {
    month = 4;
    day = april_easter_day;
  }

   // The lunar month is not exactly 30 days but a little less than 30 days. So to nullify this inconsistency, the following cases are followed:

  // Replace the 25 April with 18 April:
  if (d == 28 && e == 6 && ((11 * M + 11) % 30 < 19)) {
    day = 18;
  }

  // Replace 26 April with 19 April :
  if (d == 29 && e == 6) {
    day = 19;
  }
  
  // Assigns date to array:
  date[0] = day;
  date[1] = month;
  date[2] = year;
}

void run_easter_finder() {
  print_description();

  // Passes an array to the get_gregorian_easter_date function
  // so that we can access the date later.
  uint16_t date[3]; 
  uint16_t year = get_year();

  get_gregorian_easter_date(date, year);

  printf("Easter is on the %d/%d/%d\n", date[0], date[1], date[2]);
}

bool test_get_gregorian_easter_date(uint16_t expected_day, uint16_t expected_month, uint16_t year) {
  uint16_t date[3]; 
  uint16_t expected_date[] = {expected_day, expected_month, year};
  get_gregorian_easter_date(date, year);

  if (date[0] != expected_date[0]) { 
    return false;
  }

    if (date[1] != expected_date[1]) { 
    return false;
  }

    if (date[2] != expected_date[2]) { 
    return false;
  }

  return true;
}

// Tests easter date function using Gauss' Easter Algorithm
bool test_get_gauss_easter_date(uint16_t expected_day, uint16_t expected_month, uint16_t year) {
  uint16_t date[3]; 
  uint16_t expected_date[] = {expected_day, expected_month, year};
  get_gauss_easter_date(date, year);

  if (date[0] != expected_date[0]) { 
    return false;
  }

  if (date[1] != expected_date[1]) { 
    return false;
  }

  if (date[2] != expected_date[2]) { 
    return false;
  }

  return true;
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
  printf("\nRunning tests 🧪: \n\n");
    // Results should be (yyyy-mm-dd):
    // - `1777` : `[30,3,1777]`
    // - `1800` : `[13,4,1800]`
    // - `1876` : `[16,4,1876]`
    // - `1961` : `[2,4,1961]`
    // - `2000`: `[23, 4, 2000]`
    // - `2011`: `[24, 4, 2011]`
    // - `2020` : `[12, 4, 2020]`
    // - `2023` : `[9,4,2023]`
    // - `2024` : `[31, 3, 2024]`
    // - `2025` : `[24, 4, 2025]`
    test("Anonymous Easter Algorithm: 1777 returns 30/3/1777 for Easter ", test_get_gregorian_easter_date(30,3,1777));
    test("Anonymous Easter Algorithm: 1800 returns 13/4/1800 for Easter ", test_get_gregorian_easter_date(13,4,1800));
    test("Anonymous Easter Algorithm: 1876 returns 16/4/1876 for Easter ", test_get_gregorian_easter_date(16,4,1876));
    test("Anonymous Easter Algorithm: 1961 returns 2/4/1961 for Easter  ", test_get_gregorian_easter_date(2,4,1961));
    test("Anonymous Easter Algorithm: 2000 returns 23/4/2000 for Easter ", test_get_gregorian_easter_date(23,4,2000));
    test("Anonymous Easter Algorithm: 2011 returns 24/4/2011 for Easter ", test_get_gregorian_easter_date(24,4,2011));
    test("Anonymous Easter Algorithm: 2020 returns 12/4/2020 for Easter ", test_get_gregorian_easter_date(12,4,2020));
    test("Anonymous Easter Algorithm: 2023 returns 9/4/2023 for Easter  ", test_get_gregorian_easter_date(9,4,2023));
    test("Anonymous Easter Algorithm: 2024 returns 31/4/2024 for Easter ", test_get_gregorian_easter_date(31,3,2024));
    test("Anonymous Easter Algorithm: 2025 returns 24/4/2025 for Easter ", test_get_gregorian_easter_date(20,4,2025));

    // Spacer
    printf("\n\n");

    test("Gauss' Easter Algorithm: 1777 returns 30/3/1777 for Easter ", test_get_gauss_easter_date(30,3,1777));
    test("Gauss' Easter Algorithm: 1800 returns 13/4/1800 for Easter ", test_get_gauss_easter_date(13,4,1800));
    test("Gauss' Easter Algorithm: 1876 returns 16/4/1876 for Easter ", test_get_gauss_easter_date(16,4,1876));
    test("Gauss' Easter Algorithm: 1961 returns 2/4/1961 for Easter  ", test_get_gauss_easter_date(2,4,1961));
    test("Gauss' Easter Algorithm: 2000 returns 23/4/2000 for Easter ", test_get_gauss_easter_date(23,4,2000));
    test("Gauss' Easter Algorithm: 2011 returns 24/4/2011 for Easter ", test_get_gauss_easter_date(24,4,2011));
    test("Gauss' Easter Algorithm: 2020 returns 12/4/2020 for Easter ", test_get_gauss_easter_date(12,4,2020));
    test("Gauss' Easter Algorithm: 2023 returns 9/4/2023 for Easter  ", test_get_gauss_easter_date(9,4,2023));
    test("Gauss' Easter Algorithm: 2024 returns 31/4/2024 for Easter ", test_get_gauss_easter_date(31,3,2024));
    test("Gauss' Easter Algorithm: 2025 returns 24/4/2025 for Easter ", test_get_gauss_easter_date(20,4,2025));

    printf("\nTest job finished. \n\n");
}
