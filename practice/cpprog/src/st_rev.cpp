#include <iostream>
#include <string>

using namespace std;


int main()
{
  char s[] = "Sibasis";
  char tmp;
  int i = 0, j = 0;
  int len = 0;
  while(s[i] != 0)
  {
    len++;
    i++;
  }
  j = len -1;
  for (i = 0; i < (len/2); i++, j--)
  {
    tmp = s[j];
    s[j] = s[i];
    s[i] = tmp;
  }
  
  cout << s << endl;
  
  return 0;
}
