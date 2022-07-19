#include <stdio.h>
#include <stdlib.h>

int parse(char *ar[10])
{
	for (int i = 0; i < 5;i++)
	{
	  ar[i] = (char *) malloc(sizeof(int));
    sprintf(ar[i], "%d", i);
	}
	return 0;
}

int main()
{
  char *arr[10];
	parse(arr);

	for (int i = 0; i < 5;i++)
    printf("%s", arr[i]);
	return 0;
}
