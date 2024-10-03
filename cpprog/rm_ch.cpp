#include <iostream>
#include <cstring>

using namespace std;

void remove_ch(char *s)
{
  int i = 0, idx = -1;

  while (s[i] != '\0')
  {
    if (s[i] == '_')
    {
      if (idx == -1)
      {
        idx = i;
        s[idx++] = 'X';
      }
      else
      {
        if (s[idx - 1] != 'X')
          s[idx++] = 'X';
      }
    }
    else if (idx != -1)
      s[idx++] = s[i];
    i++;
  }

  if (idx != -1)
    s[idx] = '\0';

  cout << s << endl;

  return;
}

int main()
{
  char s[] = "welcome_______to____Delhi";
  cout << s << endl;

  remove_ch(s);
  return 0;
}
