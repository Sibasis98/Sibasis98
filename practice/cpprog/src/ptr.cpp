#include <iostream>
#include <memory>

using namespace std;
int main()
{
  unique_ptr<int> ptr(new int(6));
  shared_ptr<int> ptr1(new int(9));
  shared_ptr<int> ptr2 = ptr1;

  cout << *ptr <<endl;
  cout << *ptr1 << "  " << ptr1.use_count() <<endl;
  return 0;
}
