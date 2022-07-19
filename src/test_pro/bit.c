#include <stdio.h>
#include <stdint.h>

int main()
{
  uint8_t idx = 9;
	uint16_t mask = 1 << (idx - 1);
	uint16_t uni_mask = 0x06;
	printf("mask %d uni_mask %d %d", (mask), uni_mask, mask & uni_mask);
	return 0;
}
