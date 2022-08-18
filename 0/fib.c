#include <stdio.h>
#include <inttypes.h>

uint32_t table[40];
uint16_t pointer = 0;

void computeFib(uint16_t n) {
    for (; pointer <= n; pointer++) {
        table[pointer] = table[pointer - 2] + table[pointer - 1];
    }
}

uint32_t getFib(uint16_t n) {
    if (n >= pointer) {
        computeFib(n);
    }

    return table[n];    
}

int main (void) {
    
    table[0] = 0;
    table[1] = 1;
    pointer = 2;
    
    uint16_t n = 0;
    scanf("%hu", &n);
    printf("%u\n", getFib(n));

    return 0;

}