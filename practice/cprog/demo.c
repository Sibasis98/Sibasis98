#include <stdio.h>
#include <string.h>

int main() {
// Declare an array of 25 integers
int sub[25];

// Use memset to set each byte to 1
memset(sub, 1, sizeof(sub));

// Print the value at index 2
printf("%d", sub[2]);

return 0;
}
