#include <iostream>
#include <fstream>

using namespace std;
int main()
{
  ofstream op("file.txt");
  op<<"hello world, sibasis";
  op.seekp(10);
  op<<"how are you?";
  op.close();
}
