#include <iostream>

using namespace std;

void get_max_dist(int num)
{
  int max_dist = 0;
  int first_pos = -1;
  int num_bits = 0;

  // incase of negative num, >> will always give -1
  num = abs(num);

  if (num == 1 || !num)
  {
    cout << max_dist << endl;
    return;
  }

  while(num)
  {
    if (num & 0x01)
    {
      if (first_pos == -1)
      {
        first_pos = num_bits;
        num_bits++;
      }
      else
      {
        max_dist = max(max_dist, (num_bits - first_pos - 1));
        // reset the index pos
        num_bits = 0;

        //set the curr as the first set bit
        first_pos = num_bits++;
      }
    }
    else if (first_pos != -1)
      num_bits++;

    num = num >> 1;
  }

  cout << max_dist << endl;
}

int main()
{
  int num;
  cout << "Please enter the num: -" << endl;
  cin >> num;

  get_max_dist(num);

  return 0;
}
