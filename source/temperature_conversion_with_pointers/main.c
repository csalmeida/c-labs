/* Pointer Exercise Outline: Temperature Conversion Program
   Learning Goals:

   Understand pointer declaration
   Practice passing addresses to functions
   Use pointers to modify values
   Implement basic pointer arithmetic

   Exercise Challenge:
   Create a C program that converts temperatures between Celsius and Fahrenheit using pointers. Your program should:

   Basic Requirements:

   Create functions that convert temperatures using pointer parameters
   Allow user input of temperatures
   Print converted temperatures


   Specific Pointer Usage Requirements:

   Declare pointer variables for temperatures
   Use the address-of operator & when passing variables
   Use the dereference operator * to modify values
   Create at least two functions that use pointers as parameters


   Bonus Challenges:

   Create a function that generates a temperature conversion table
   Use pointer iteration to create the table
   Handle potential input errors


   Hints to Get Started:

   Remember the conversion formulas:

   Fahrenheit = (Celsius * 9/5) + 32
   Celsius = (Fahrenheit - 32) * 5/9


   Use float * for temperature pointers
   Use scanf() to get user input
   Think about how you can pass the address of variables to functions

   Guiding Questions:

   How do you declare a pointer to a float?
   How do you get the address of a variable?
   How can you modify a value through a pointer?
   What's the difference between the variable name and its address? */

#include <stdio.h> // For printf and scanf.
#include <stdlib.h> // For return exit types.

float get_temperature();
float fahrenheit_to_celsius(float fahrenheit_temp, float *celsius_temp);
float celsius_to_fahrenheit(float celsius_temp, float *fahrenheit_temp);

float fahrenheit_temp;
float celsius_temp;

float converted_fahrenheit_temp;
float converted_celsius_temp;

int main(void) {
  printf("Type a Fahrenheit temperature:\n");
  fahrenheit_temp = get_temperature();
  // When a function needs to read or modify data in a pointer we pass it the address in memory using &.
  fahrenheit_to_celsius(fahrenheit_temp, &converted_celsius_temp);
  printf("Temperature %f Fahrenheit is %f Celsius\n", fahrenheit_temp, converted_celsius_temp);

  printf("Type a Celsius temperature:\n");
  celsius_temp = get_temperature();
  celsius_to_fahrenheit(celsius_temp, &converted_fahrenheit_temp);
  printf("Temperature %f Celsius is %f Fahrenheit\n", celsius_temp, converted_fahrenheit_temp);

  return EXIT_SUCCESS;
}


/* Asks user for temperature value */
float get_temperature() {
  float temperature;
  scanf("%f", &temperature); // Passes the address of the variable to scanf.
  return temperature;
}

/*
  This function takes in a Fahrenheit temperature value and a pointer to a Celsius temperature variable.

   The function:
   1. Converts the Fahrenheit value to Celsius using the formula (f - 32) * 5/9
   2. Stores the result in a local variable
   3. Uses the pointer (*celsius_temp) to update the variable at the memory location passed in
   4. Returns the calculated result

   The pointer allows the function to modify the original celsius_temp variable in the calling scope
   by dereferencing the memory address with *celsius_temp = result
*/
float fahrenheit_to_celsius(float fahrenheit_temp, float *celsius_temp) {
  float result = (fahrenheit_temp - 32) * 5/9;
  *celsius_temp = result;
  return result;
}

/*
  This function takes in a Celsius temperature value and a pointer to a Fahrenheit temperature variable.

  The function:
  1. Converts the Celsius value to Fahrenheit using the formula (c * 9/5) + 32
  2. Stores the calculated result in a local variable
  3. Uses pointer dereferencing (*fahrenheit_temp) to update the memory location passed in
  4. Returns the calculated result

  By using a pointer parameter (*fahrenheit_temp), the function gains direct access to modify the
  original fahrenheit_temp variable in the calling scope. When we assign a value using
  *fahrenheit_temp = result, we are writing directly to the memory location that was passed in,
  allowing the function to "return" two values - one through the return statement and one
  through the pointer parameter.
*/

float celsius_to_fahrenheit(float celsius_temp, float *fahrenheit_temp) {
  float result = (celsius_temp * 9/5) + 32;
  *fahrenheit_temp = result;
  return result;
}
