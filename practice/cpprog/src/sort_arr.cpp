#include <iostream>

using namespace std;

// 0 30 10 5  63 20
// 0 5  10 30 63 20
// 0 5  10 30 63 20
// 0 5  10 20 63 30
// 0 5  10 20 30 63
int main()
{
  int a[] = {20, 30, 10, 5, 63, 0};
  int min = -1;
  int idx = -1;

  for (int i = 0; i < 6; i++)
  {
    min = a[i];
    idx = -1;
    for (int j = i; j < 6; j++)
    {
      if (min > a[j])
      {
        min = a[j];
        idx = j;
      }
    }

    if (idx != -1)
    {
      a[idx] = a[i];
      a[i] = min;
    }
  }

  for (int i = 0; i < 6; i++)
    cout << a[i] << endl;

  return 0;
}
