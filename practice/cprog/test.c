#include<stdio.h>
#include <stdlib.h>
int main()
{
  int *ptr = (int*)malloc(0);

  printf("%p\n", ptr);
  ptr = (int *)realloc(ptr, 0);
  printf("%p\n", ptr);

  return 0;

}
