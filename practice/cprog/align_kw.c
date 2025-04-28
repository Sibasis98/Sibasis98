#include <stdio.h>

struct __attribute__((aligned(16))) AlignedStruct {
    int a;
    double b;
    double c;
};

/*__declspec(align(16)) struct AlignedStruct1 {
    int a;
    double b;
};
*/

int main() {
    printf("Alignment of AlignedStruct: %zu\n",  _Alignof(struct AlignedStruct);
    //printf("Alignment of AlignedStruct: %zu\n", _Alignof(struct AlignedStruct1));
    return 0;
}
