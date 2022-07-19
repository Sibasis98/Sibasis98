#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main()
{
  char buff[1024];
  char arr[1024];
  int n;
  int even[1024];
  int odd[1024];

  scanf("%d", &n);
  scanf("%s", &arr);

  qsort(arr, 5, sizeof(int), cmpfunc);

  char *ptr=arr[0];
  char *ptr1;
  int prev = 0;
  for(int i = 0;i < n:i++)
  {
    if((a[i]%2 == 0) && (!prev))
    {
      ptr1 = ptr;
      prev = 1; 
    }
    else
      ptr1 = ptr;

    ptr += 2;

    len += sprintf(buff+len, "%d", ptr1);
    if(i != n-1)
      len += sprintf(buff+len, ",");
    prev = prev?0:1;
  }
  return 0;
}

