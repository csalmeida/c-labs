#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h> // Allows integer sizes to be specified.
#include <stdbool.h> // Allows the bool type to be used.
#include <math.h>

// Core functions:
void print_description();
uint16_t get_day();
uint16_t get_month();
uint16_t get_year();
uint16_t get_hour();
uint16_t get_minutes();
uint16_t get_seconds();
uint64_t convert_to_jdn(uint16_t day, uint16_t month, uint16_t year);
double calculate_fraction_of_day(uint16_t hour, uint16_t minutes, uint16_t seconds);
double calculate_jd(uint64_t jdn, uint16_t hour, uint16_t minutes, uint16_t seconds);
void run_jdn_converter();


// Test related functions:
bool assert(bool predicate);
bool test(const char *name, bool passed);
void tests();

int main() {
  // Requests year as input and prints a result to the terminal:
  // run_jdn_converter();

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
            printf("🛑 Invalid day. Please enter a day as numbers e.g. 14.\n");
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

// Prompt user to enter an hour, once captured, it returns it.
// It only accepts a number as an input.
uint16_t get_hour() {
    uint16_t max_hour = 23; // Max is 23 because 24 == 0.
    uint32_t user_number;

    // Loop until a valid integer is entered
    while (1) {
        printf("Please type in the hour: ");

        // Check if the input is an integer
        if (scanf("%d", &user_number) == 1 && user_number <= max_hour) {
            return (uint32_t)user_number; // Exit the loop if a valid integer is entered
        } 
          else if (user_number > max_hour) {
            // Clear the input buffer in case of invalid input
            while (getchar() != '\n');
            printf("🛑 Invalid hour. Please enter a hour up to %d. \n", max_hour);
          } else {
            // Clear the input buffer in case of invalid input
            while (getchar() != '\n');
            printf("🛑 Invalid hour. Please enter a hour as numbers with no leading zeroes e.g. 3 or 14.\n");
        }
    }
    return EXIT_SUCCESS;
}

// Prompt user to enter minutes within an hour, once captured, it returns it.
// It only accepts a number as an input.
uint16_t get_minutes() {
    uint16_t max_minutes = 59; // Max is 59 because 60 == 0.
    uint32_t user_number;

    // Loop until a valid integer is entered
    while (1) {
        printf("Please type in the minutes: ");

        // Check if the input is an integer
        if (scanf("%d", &user_number) == 1 && user_number <= max_minutes) {
            return (uint32_t)user_number; // Exit the loop if a valid integer is entered
        } 
          else if (user_number > max_minutes) {
            // Clear the input buffer in case of invalid input
            while (getchar() != '\n');
            printf("🛑 Invalid minutes. Please enter minutes up to %d. \n", max_minutes);
          } else {
            // Clear the input buffer in case of invalid input
            while (getchar() != '\n');
            printf("🛑 Invalid minutes. Please enter minutes as numbers with no leading zeroes e.g. 3 or 14.\n");
        }
    }
    return EXIT_SUCCESS;
}

// Prompt user to enter seconds within an hour, once captured, it returns it.
// It only accepts a number as an input.
uint16_t get_seconds() {
    uint16_t max_seconds = 59; // Max is 59 because 60 == 0.
    uint32_t user_number;

    // Loop until a valid integer is entered
    while (1) {
        printf("Please type in the seconds: ");

        // Check if the input is an integer
        if (scanf("%d", &user_number) == 1 && user_number <= max_seconds) {
            return (uint32_t)user_number; // Exit the loop if a valid integer is entered
        } 
          else if (user_number > max_seconds) {
            // Clear the input buffer in case of invalid input
            while (getchar() != '\n');
            printf("🛑 Invalid seconds. Please enter seconds up to %d. \n", max_seconds);
          } else {
            // Clear the input buffer in case of invalid input
            while (getchar() != '\n');
            printf("🛑 Invalid seconds. Please enter seconds as numbers with no leading zeroes e.g. 5 or 32.\n");
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
  double jdn = b * 365 + (b / 4) - (b / 100) + (b / 400) + e - 32045;

  // FIXME: return JDN instead when we have it
  return jdn;
}

// Calculates the fraction of a day based on a time.
double calculate_fraction_of_day(uint16_t hour, uint16_t minutes, uint16_t seconds) {
  uint8_t seconds_per_minute = 60;
  uint16_t seconds_per_hour = 3600;
  uint32_t seconds_per_day = 86400; // 60sec * 60min * 24hours
  
  // Convert hours and minutes to seconds:
  uint32_t hour_in_seconds = hour * seconds_per_hour;
  uint32_t minutes_in_seconds = minutes * seconds_per_minute;

  // Add the time up:
  uint32_t total_seconds = hour_in_seconds + minutes_in_seconds + seconds;
  
  // Dividing by the seconds in a day results in a fraction. e.g. 0.1 is 10% of a day, 0.5 is 50%.
  double fraction_of_day = (double) total_seconds / (double) seconds_per_day;
  return fraction_of_day;
}

// Receives a Julian Day Number and calculates the time 
// represented as a fraction, appended to the JDN result.
double calculate_jd(uint64_t jdn, uint16_t hour, uint16_t minutes, uint16_t seconds) {
  // Since there are 24 hours in a day, dividing the hour by 24 gives the fraction of the day that has passed.
  // We subtract 12 since the Julian Date System, the day starts at noon (12:00 PM)
  double hour_fd = (double) (hour - 12) / 24;

  //There are 60 minutes in an hour, so dividing the minute by 1440 (which is 24×6024×60) gives the fraction of the day represented by the minutes.
  double minutes_fd = (double) minutes / 1440; 

  // Since there are 60 seconds in a minute and 60 minutes in an hour (totaling 3600 seconds in an hour), dividing the seconds by 86400 (which is 24×60×6024×60×60) gives the fraction of the day represented by the seconds.
  double seconds_fd = (double) seconds / 86400; 

  double fraction_of_time = hour_fd + minutes_fd + seconds_fd;

  // Needs an adjustment so that the fractional part is always positive.
  // A negative fraction_of_time would lead to incorrect day.
  // Compared with Nasa's results: https://ssd.jpl.nasa.gov/tools/jdc/#/cd
  fraction_of_time = fraction_of_time + 1.0;
    
  double jd = (double) jdn + fraction_of_time;    
  return jd;
}

// Requests date (day, month and year) input and prints the resulting JDN to the terminal.
void run_jdn_converter() {
  print_description();

  // Capture a date from the user:
  uint16_t day = get_day();
  uint16_t month = get_month();
  uint16_t year = get_year();
  uint16_t hour = get_hour();
  uint16_t minutes = get_minutes();
  uint16_t seconds = get_seconds();

  uint64_t jdn = convert_to_jdn(day, month, year);
  double jd = calculate_jd(jdn, hour, minutes, seconds);

  printf("The Julian Day Number for %d/%d/%d %d:%d:%d is: %.7f\n", day, month, year, hour, minutes, seconds, jd);
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

// Asserts if two double numbers are equal.
bool assert_double_equals(double value, double result) {
  return fabs(value-result) < 0.00001f;
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

    test("0 as day should fail                              ", assert_exit_failure(convert_to_jdn(0, 12, 2023)));
    test("0 as month should fail                            ", assert_exit_failure(convert_to_jdn(25, 0, 2023)));
    test("0 as year should fail                             ", assert_exit_failure(convert_to_jdn(25,12,0)));

    test("day over 31 should fail                           ", assert_exit_failure(convert_to_jdn(32, 12, 2023)));
    test("month over 12 should fail                         ", assert_exit_failure(convert_to_jdn(25, 13, 2023)));


    // Results should be (yyyy-mm-dd):
    // - `1600-11-15` : `2305766`
    // - `1969-03-13` : `2440293`
    // - `1984-02-23` : `2445753`
    // - `1990-07-05` : `2448077`
    // - `2000-03-10`: `2451613`
    // - `2011-11-18`: `2455883`
    // - `2020-04-15` : `2458954`
    // - `2023-10-17` : `2460234`
    // - `2024-01-24` : `2460333`
    test("15-11-1600 converts to JDN 2305766                ", assert_uint_equals(convert_to_jdn(15, 11, 1600), 2305766));
    test("13-03-1969 converts to JDN 2440293                ", assert_uint_equals(convert_to_jdn(13, 3, 1969), 2440293));
    test("23-02-1984 converts to JDN 2445753                ", assert_uint_equals(convert_to_jdn(23, 2, 1984), 2445753));
    test("05-07-1990 converts to JDN 2448077                ", assert_uint_equals(convert_to_jdn(5, 7, 1990), 2448077));
    test("10-03-2000 converts to JDN 2451613                ", assert_uint_equals(convert_to_jdn(10, 3, 2000), 2451613));
    test("18-11-2011 converts to JDN 2455883                ", assert_uint_equals(convert_to_jdn(18, 11, 2011), 2455883));
    test("15-04-2020 converts to JDN 2458954                ", assert_uint_equals(convert_to_jdn(15, 4, 2020), 2458954));
    test("17-10-2023 converts to JDN 2460234                ", assert_uint_equals(convert_to_jdn(17, 10, 2023), 2460234));
    test("24-01-2024 converts to JDN 2460333                ", assert_uint_equals(convert_to_jdn(24, 1, 2024), 2460333));


    // Second set of results should be (yyyy-mm-dd hh:mm:ss):
    // - `1600-11-15 12:15:30` : `2305767.0107639`
    // - `1969-03-13 09:56:43` : `2440293.9143866`
    // - `1984-02-23 16:24:01` : `2445754.1833449`
    // - `1990-07-05 19:47:42` : `2448078.3247917`
    // - `2000-03-10 23:06:03`:  `2451614.4625347`
    // - `2011-11-18 17:33:05`:  `2455884.2313079`
    // - `2020-04-15 07:22:07` : `2458954.8070255`
    // - `2023-10-17 09:21:57` : `2460234.8902431`
    // - `2024-01-24 10:57:03` : `2460333.9562847`
    test("15-11-1600 12:15:30 converts to JD 2305767.010764 ", assert_double_equals(calculate_jd(2305766, 12, 15, 30), 2305767.0107639));
    test("13-03-1969 09:56:43 converts to JD 2440293.9143866", assert_double_equals(calculate_jd(2440293, 9, 56, 43), 2440293.9143866));
    test("23-02-1984 16:24:01 converts to JD 2445754.1833449", assert_double_equals(calculate_jd(2445753, 16, 24, 1), 2445754.1833449));
    test("05-07-1990 19:47:42 converts to JD 2448078.3247917", assert_double_equals(calculate_jd(2448077, 19, 47, 42), 2448078.3247917));
    test("10-03-2000 23:06:03 converts to JD 2451614.4625347", assert_double_equals(calculate_jd(2451613, 23, 6, 3), 2451614.4625347));
    test("18-11-2011 17:33:05 converts to JD 2455884.2313079", assert_double_equals(calculate_jd(2455883, 17, 33, 5), 2455884.2313079));
    test("15-04-2020 07:22:07 converts to JD 2458954.8070255", assert_double_equals(calculate_jd(2458954, 7, 22, 7), 2458954.8070255));
    test("17-10-2023 09:21:57 converts to JD 2460234.8902431", assert_double_equals(calculate_jd(2460234, 9, 21, 57), 2460234.8902431));
    test("24-01-2024 10:57:03 converts to JD 2460333.9562847", assert_double_equals(calculate_jd(2460333, 10, 57, 3), 2460333.9562847));

  printf("\nTest job finished. \n\n");
}

