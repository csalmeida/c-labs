#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Sandbox program running...\n");

  int x = 4;

  // x is defined and can be accessed directly.
  // An address is also assigned to x.
  printf("The value of x is: %d\n", x);
  printf("The address of x is: %p\n", &x);

  int *pointer_x = &x;

  // pointer_x stores the address of x, and the value is dereferenced so that it can be accessed.
  // The address is what is accessed by default if pointer_x is not derefrenced.
  printf("The value of pointer_x is: %d\n", *pointer_x);
  printf("The address of pointer_x is: %p\n", pointer_x);


  int *pointer_y = pointer_x;

  // The following code points to `pointer_x` that points to `x`.
  // This is not a copy.
  printf("The value of pointer_y is: %d\n", *pointer_y);
  printf("The address of pointer_y is: %p\n", pointer_y);

  int y = *pointer_y;

  // In this case there's a copy being made because the value of the pointer is dereferenced into `y`.
  // The address of y is different than the ones above.
  printf("The value of y is: %d\n", y);
  printf("The address of y is: %p\n", &y);

  return EXIT_SUCCESS;
}
