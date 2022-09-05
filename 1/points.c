/*
По данным n отрезкам необходимо найти множество точек минимального размера, для которого каждый из отрезков содержит хотя бы одну из точек.

В первой строке дано число 1 ≤ n ≤ 100 отрезков. 
Каждая из последующих n строк содержит по два числа 0 ≤l ≤ r ≤ 10**9, задающих начало и конец отрезка. 
Выведите оптимальное число m точек и сами m точек. Если таких множеств точек несколько, выведите любое из них.
*/

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

uint32_t min(uint32_t a, uint32_t b) {
    if (a < b) {
        return a;
    }
    return b;
}

typedef struct Segment {
    uint32_t begin;
    uint32_t end;
} Segment;

int compare_segment(const void *a, const void *b) {
    Segment *x = (Segment *)a;
    Segment *y = (Segment *)b;
    return x->begin - y->begin;

}

int main(void) {
    uint16_t n = 0;
    scanf("%hu", &n);

    Segment segments[n];

    uint32_t points_array[n * 2];
    uint16_t array_pointer = 0;

    for (uint16_t i = 0; i < n; i++) {
        scanf("%u %u", &(segments[i].begin), &(segments[i].end));
    }

    qsort(segments, n, sizeof(*segments), compare_segment);

    uint16_t i = 0;
    uint32_t point = segments[0].begin;
    uint32_t end = segments[0].end;

    while (i < n) {
        if (segments[i].begin <= end) {
            end = min(end, segments[i].end);
        }
        else {
            points_array[array_pointer++] = point;
            end = segments[i].end;
        }
        point = segments[i].begin;
        i++;
    }
    points_array[array_pointer++] = point;

    printf("%hu\n", array_pointer);
    for (uint16_t i; i < array_pointer; i++) {
        printf("%u ", points_array[i]);
    }
    
    return 0;
}