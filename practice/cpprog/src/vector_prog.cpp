#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

// size
// capacity
// push_back
// pop_back
// at
// resize
// emplace
// clear
int main()
{
  vector<int> vt{1,2,3,4};

  vector<int>::iterator itr;
  int i = 0;

/*  for (i = 0; i < vt.size(); i++)
    cout << vt.at(i) << endl;

  for (itr = vt.begin(); itr != vt.end(); ++itr)
    cout << *itr << endl;

  cout << vt.size() << endl;
*/
  vt.resize(2);
  for (itr = vt.begin(); itr != vt.end(); ++itr)
    cout << *itr << endl;

  vt.clear();

  cout << vt.size() <<endl;
  cout << vt.capacity() << endl;
  return 0;
}
