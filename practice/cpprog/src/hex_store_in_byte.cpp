#include <iostream>
#include <iomanip>

using namespace std;

void store_in_bytearr(long long num)
{
  uint8_t byte_arr[8];
  int index = 0;
  while(num)
  {
    byte_arr[index++] = num & 0xff;
    num = num >> 8;
  }
  for (int i = 0; i < index; i++)
    cout << hex << byte_arr[i] <<endl;

  num = 0x2f;
    cout << hex << num <<endl;
    //printf("%0x\n", byte_arr[i]);
}

int main() {
  // Write C code here
  long long num = 0xBB89AAFF;
  store_in_bytearr(num);

  return 0;
}
