#include <stdio.h>
int main() {
    int a[5] = {1, 2, 3, 4, 5};
    unsigned total = 0;
    /**
     * In initial code:"j<sizeof(a)", but sizeof(a) equals 20bytes,it should be divided "by sizeof(int)"
    */
    for (int j = 0; j < sizeof(a)/sizeof(int); j++) {
        total += a[j];
    }

    printf("sum of array is %d\n", total);
}