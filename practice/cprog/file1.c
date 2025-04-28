#include <stdio.h>

int main()
{
  FILE *fp = fopen("Myprg.txt", "a");
  fprintf(fp, "Hello world");
  fprintf(stderr, "Hello world");

  fclose(fp);
}
