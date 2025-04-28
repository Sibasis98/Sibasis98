#include <iostream>

using namespace std;

void sum_digit(int num)
{
  int sum = 0;
  int rem = 0;
  while (num)
  {
    rem = num % 10;
    num /= 10;
    sum += rem;
    if (sum >= 10)
    {
      rem = sum % 10;
      // two single digit sum max will be 18, so 1 will be the carry one, so adding 1 default + rem
      sum = 1 + rem;
    }
  }

  cout << sum << endl;
  return;
}

int main()
{
  int num;
  cout << "Enter the num " << endl;
  cin >> num;

  sum_digit(num);

  return 0;
}
