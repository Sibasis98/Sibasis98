#include <iostream>
#include <vector>
#include <algorithm>

//#define find_maj_elm find_maj_elm_algo
#define find_maj_elm find_maj_elm_opt

// This will work iff one elem is the majority
//Moore's voting algorithm
// it will return the ans as per the freq
int find_maj_elm_algo(std::vector<int> vt)
{
  int freq = 0;
  int ans = -1;
  for (int i = 0; i < vt.size(); i++)
  {
    if (freq == 0)
      ans = vt[i];

    if (ans == vt[i])
      freq++;
    else
      freq--;
  }

  return ans;
}

int find_maj_elm_opt(std::vector<int> vt)
{
  sort(vt.begin(), vt.end());
  int freq = 0;
  int prev = 0;
  int maj = vt.size()/2;

  for (int num : vt)
  {
    if (prev != num)
    {
      freq = 0;
      prev = num;
    }

    freq++;
    if (freq > maj)
      return num;
  }
  return -1;
}

int main()
{
  std::vector<int> vt{1, 2, 2, 2, 1};
  //std::vector<int> vt{1, 1, 2};

  int ans = find_maj_elm(vt);

  std::cout << ans << std::endl;

  return 0;
}
