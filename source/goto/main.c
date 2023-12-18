#include <stdio.h>
#include <stdlib.h>

// Mock initialization functions:
int initialize_1(void);
int initialize_2(void);
int initialize_3(void);
void deinitialize_1(void);
void deinitialize_2(void);
void deinitialize_3(void);


int complex_function_goto(void);
int complex_function_if(void);

int main() {
  printf("Using goto: %d \n", complex_function_goto());
  printf("Using if: %d \n", complex_function_if());

  return EXIT_SUCCESS;
}

int complex_function_goto(void) {
  if (initialize_1() != EXIT_SUCCESS) { goto out1; } 
  if (initialize_2() != EXIT_SUCCESS) { goto out2; }
  if (initialize_3() != EXIT_SUCCESS) { goto out3; }
  return EXIT_SUCCESS;

  out3: deinitialize_3();
  out2: deinitialize_2();
  out1: deinitialize_1();
  return EXIT_FAILURE; 
}

int complex_function_if(void) {
  if (initialize_1() != EXIT_SUCCESS) { 
    deinitialize_1();
  } 

  if (initialize_2() != EXIT_SUCCESS) { 
    deinitialize_2();
  } 

  if (initialize_3() != EXIT_SUCCESS) { 
    deinitialize_3(); 
  }

  if (initialize_3() != EXIT_SUCCESS || initialize_2() != EXIT_SUCCESS || initialize_1() != EXIT_SUCCESS) {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

int initialize_1() {
  return EXIT_SUCCESS;
}

int initialize_2() {
  return EXIT_SUCCESS;
}

int initialize_3() {
  return EXIT_FAILURE;
}

void deinitialize_1() {}
void deinitialize_2() {}
void deinitialize_3() {}