# include <stdio.h>
# include <stdlib.h>

// Describes the struct fields:
struct student { 
  char name[32];
  short class_year;
  char age;
};

int main() {
  // Defines an instance of a struct:
  struct student s = { 
    "H. Sommers", 
    2026, 
    5 
  };

  // Prints struct data and size:
  printf("An example student: %s, %d, %d\n", s.name, s.class_year, s.age); 
  printf("Size of a student struct: %lu\n", sizeof(struct student)); 

  return EXIT_SUCCESS;
}
