#include <iostream>
#include <vector>

std::vector<int> find_target_sum_idx(int arr[], int arr_len, int target)
{
  int i = 0;
  int j = arr_len - 1;
  std::vector<int> vt;

  while (i < j)
  {
    int sum = arr[i] + arr[j];

    if (sum == target)
    {
      vt.push_back(i);
      vt.push_back(j);
      return vt;
    }
    else if (sum < target)
      i++;
    else
      j--;
  }
  return vt;
}

int main()
{
  int arr[] = {2, 7, 11, 15};
  int target = 18;
  int arr_len = sizeof(arr)/ sizeof(arr[0]);

  std::vector<int> vt = find_target_sum_idx(arr, arr_len, target);

  if (vt.empty())
    std::cout << "No element found." << std::endl;
  else
    std::cout << vt[0] << "," << vt[1] << std::endl;

  return 0;
}
