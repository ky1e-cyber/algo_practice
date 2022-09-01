#include <stdio.h>
#include <inttypes.h>

uint32_t gcd(uint32_t a, uint32_t b) { //- a / b
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    while ((a != 0) & (b != 0)) {
        if (a >= b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    return gcd(a, b);
}

int main(void) {
    uint32_t a, b;
    scanf("%u %u", &a, &b);
    printf("%u\n", gcd(a, b));
    return 0;
}