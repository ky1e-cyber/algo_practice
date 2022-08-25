/*

Дано число 1≤n≤107, необходимо найти последнюю цифру n-го числа Фибоначчи.
Как мы помним, числа Фибоначчи растут очень быстро, поэтому при их вычислении нужно быть аккуратным с переполнением. 
В данной задаче, впрочем, этой проблемы можно избежать, поскольку нас интересует только последняя цифра числа Фибоначчи: 
если 0≤a,b≤9 0 — последние цифры чисел F_i и F_{i+1} соответственно, то (a + b) mod 10 — последняя цифра числа F_{i+2}​.

Sample Input:
841645

Sample Output:
5

*/

#include <stdio.h>
#include <inttypes.h>


uint8_t getFibLastDigit(uint32_t n) {
    uint8_t prev_digit = 0;
    uint8_t prevprev_digit = 1;
    uint8_t digit;

    for (uint32_t i = 1; i <= n; i++) {
        digit = (prev_digit + prevprev_digit) % 10;
        prevprev_digit = prev_digit;
        prev_digit = digit;
    }

    return digit;
}

int main (void) {
    
    uint32_t n = 0;
    scanf("%u", &n);
    printf("%hhu\n", getFibLastDigit(n));

    return 0;

}