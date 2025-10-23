#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

  char *p = alloc(20);

  strcpy(p, "hello world");
  printf("\nstring: %s\n", p);

  return 0;
}