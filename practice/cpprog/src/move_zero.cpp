#include <iostream>

#define move_zero_elm move_zero_elm_idx
//#define move_zero_elm move_zero_elm_ptr

void move_zero_elm_ptr(int arr[], int arr_len)
{
  int *sptr = &arr[0];
  int *ptr = &arr[0];

  if (!arr_len || (arr_len == 1))
    return;

  while (ptr != &arr[arr_len - 1])
  {
    if (*sptr != 0 && *ptr != 0)
    {
      sptr++;
    }
    else if (*ptr != 0)
    {
      *sptr = *ptr;
      *ptr = 0;
      sptr++;
    }
    ptr++;
  }

  if (*ptr != 0 && *sptr == 0)
  {
    *sptr = *ptr;
    *ptr = 0;
  }
}

void move_zero_elm_idx(int arr[], int arr_len)
{
  int sidx = 0;

  if (!arr_len || (arr_len == 1))
    return;

  for (int i = 0; i < arr_len; i++)
  {
    if (arr[i] != 0)
    {
      if (sidx != i)
      {
        arr[sidx] = arr[i];
        arr[i] = 0;
      }
      sidx++;
    }
  }
}

void print_arr(int arr[], int arr_len)
{
  for (int i = 0; i < arr_len; i++)
    std::cout << arr[i] << std::endl;

  std::cout << "End of arr" << std::endl;
}

int main()
{
  int arr[] = {1, 3, 0, 0, 12, 0};
  int arr1[] = {0, 0, 0, 0, 0, 0};
  int arr2[] = {99, 21, 1450, 9, 12, 2};
  int arr3[] = {0, 0, 0, 0, 0, 1};

  int arr_len = sizeof(arr)/sizeof(arr[0]);

  move_zero_elm(arr, arr_len);
  move_zero_elm(arr1, arr_len);
  move_zero_elm(arr2, arr_len);
  move_zero_elm(arr3, arr_len);

  print_arr(arr, arr_len);
  print_arr(arr1, arr_len);
  print_arr(arr2, arr_len);
  print_arr(arr3, arr_len);
}
