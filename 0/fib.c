/*

Дано целое число 1 ≤ n ≤ 40, необходимо вычислить n-е число Фибоначчи 
(напомним, что F_0 = 0; F_1 = 1; F_n = F_{n-1} + F_{n-2} при n≥2).

Sample Input:
3

Sample Output:
2

*/

#include <stdio.h>
#include <inttypes.h>

uint32_t table[40];
size_t pointer = 0;

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