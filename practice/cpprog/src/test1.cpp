#include <iostream>
#include <vector>

int main()
{
  vector<int> vt;
  vt.push_back(5);
  vt.push_back(6);

  for (auto itr = vt.begin(); itr != vt.end(); ++itr)
    std:cout << *itr << std:endl;

  cout << "\n\n";

  for (int num : vt)
    std:cout << num << std:endl;

  return 0;
}
