#include <iostream>

// arr - [4  1  2  3  5  8 ]
//     - [19 22 21 20 18 15]
using namespace std;

int main()
{
  int arr[] = {4,1,2,3,5,8};
  int arr_len = sizeof(arr)/sizeof(arr[0]);
  int tmp = 0;

  for (int i = 0; i < arr_len; i++)
    tmp += arr[i];

  for (int i = 0; i < arr_len; i++)
  {
    arr[i] = tmp - arr[i];
    cout << arr[i] <<" ";
  }

  return 0;
}
