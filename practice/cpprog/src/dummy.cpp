#include <iostream>

using namespace std;

void add_fun(int &c)
{
  int d = c + 2;
  cout << d << endl;
}

int main()
{
  int a = 10;
  int &addr = a;

  cout << addr << endl;
  cout << &addr << endl;
  cout << &a << endl;

  addr = 11;
  cout << addr << endl;
  cout << &addr << endl;
  cout << &a << endl;

  add_fun(addr);
  cout << addr << endl;
  return 0;
}
