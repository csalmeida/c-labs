#include <stdio.h>
#include <stdlib.h>

int to_bits(int bytes) {
  int bits = bytes * 8;
  return bits; 
}

int main(void) {
  char c = 'a';
  short s = 0xbeef;
  int i = 100000;
  long l = 100000000L;
  long long ll = 60000000000LL;
  
  printf("A char is %lu bytes and %d bits\n", sizeof(c), to_bits(sizeof(c)));
  printf("A short is %lu bytes and %d bits\n", sizeof(s), to_bits(sizeof(s)));
  printf("An int is %lu bytes and %d bits\n", sizeof(i), to_bits(sizeof(i)));
  printf("A long is %lu bytes and %d bits\n", sizeof(l), to_bits(sizeof(l)));
  printf("A long long is %lu bytes and %d bits \n", sizeof(ll), to_bits(sizeof(ll)));

  return EXIT_SUCCESS;
}