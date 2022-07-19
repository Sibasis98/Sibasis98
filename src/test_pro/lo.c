#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n;
  int arr[1024];
  int sum = 0;

  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  for(int i = 0; i < n; i++)
  {
    if(arr[i] % 3 == 0)
      sum += arr[i]; 
  }
  printf("%d", sum);
  return 0;
}
