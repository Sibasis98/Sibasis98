#include <stdio.h>

int main()
{
  FILE *fp = fopen("my/file.txt", "w");

  if (fp)
  {
    printf("Hello");
    fclose(fp);
  }
  else
    printf("Hi");

  return 0;
}
