#include <iostream>
#include <vector>
#include <algorithm>

int find_nxt_max_num(int num)
{
  std::vector<int> nums;

  while (num != 0)
  {
    nums.push_back(num % 10);
    num /= 10;
  }

  reverse(nums.begin(), nums.end());

  int digit_cnt = nums.size(); // it will give the total digit present in the number
  int scnd_max_num_idx = digit_cnt - 2; // taking -2, as we will compare the jth and jth + 1 value
  int nxt_last_idx;

  while (scnd_max_num_idx >= 0 && (nums[scnd_max_num_idx] > nums[scnd_max_num_idx + 1]))
    --scnd_max_num_idx;

  nxt_last_idx = scnd_max_num_idx;
  // get the next larger number as compare to current number
  while (scnd_max_num_idx != (digit_cnt - 1) && (nums[scnd_max_num_idx] < nums[scnd_max_num_idx + 1]))
    scnd_max_num_idx++;

  std::swap(nums[nxt_last_idx], nums[scnd_max_num_idx]);

  // to get the correct order of the number
  reverse(nums.begin() + nxt_last_idx + 1, nums.end());

  int new_max_num = 0;

  for (auto n: nums)
    new_max_num = new_max_num * 10 + n;
  return new_max_num;
}

int main()
{
  int num = 12348976;

  std::cout << "Given number:- \n" << num << std::endl;
  int next_max_num = find_nxt_max_num(num);

  std::cout << next_max_num << std::endl;
  return 0;
}
