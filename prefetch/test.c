#include <stdio.h>

int main ()
{
  __uint64_t value = 0;

  printf("Manipulating data prefething register\n");

  asm volatile("mrs %0, S3_1_C15_C2_0" : "=r" (value)); // read register
  printf("Reading old S3_1_C15_C2_0 = %lx)\n", value);
  printf("Done manipulating data prefetching register\n");
}