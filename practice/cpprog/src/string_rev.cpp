#include <iostream>
#include <string>

using namespace std;

#define CHECK_REPL(min_idx, max_idx)        \
{                                           \
  string s = str.substr(min_idx, max_idx);  \
  if (s == sub_str)                         \
    s = repl_str;                           \
  new_str += s;                             \
}

string string_repl_rev(string str, string sub_str, string repl_str)
{
  int max = -1;
  string new_str;

  for(int i = str.length(); i >= 0; i--)
  {
    if (max == -1)
      max = i;

    if (str[i] == ' ')
    {
      CHECK_REPL(i+1, max -i);
      new_str += ' ';
      max = -1;
    }
  }

  if (max != -1)
    CHECK_REPL(0, max + 1);

  return new_str;
}

int main()
{
  string str = "There is a boy from noida";
  string sub_str = "boy";
  string repl_str = "girl";

  str = string_repl_rev(str, sub_str, repl_str);

  cout << str << endl;
}
