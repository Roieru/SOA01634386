#include <stdio.h>
#include <stdlib.h>

int main() {
  fprintf(stderr, "Generating all numbers from 1 to 100\n");
  for (int i = 2; i <= 100; i++) {
    printf("%d\n", i);
  }
  //fprintf(stderr, "Sending end\n");
  printf("%d\n",-1);
}