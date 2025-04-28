#include <iostream>

using namespace std;

int main()
{
  int a[] = {1,2,3,4};
  int *p = a;
  cout << p << endl;
  cout << *(p+3) << endl;

  return 0;
}
