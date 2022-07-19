#include <stdio.h>
#include <stdint.h>

int main()
{
  uint16_t mask = 0x01;
	int t = 32 - __builtin_clz(mask);
  printf("%d", t);
	return 0;
}
