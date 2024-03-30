#include<stdio.h>
#include<stdlib.h>

uint32_t reverseBits(uint32_t n) {
    unsigned int mask = 1<<31, res = 0;
    for(int i = 0; i < 32; ++i) {
        if(n & 1) res |= mask;
        mask >>= 1;
        n >>= 1;
    }
    return res;
}


int main() {

    int num = 0x444;
    num = reverseBits(num);
    printf("\nNum0x%x\n", num);
}
