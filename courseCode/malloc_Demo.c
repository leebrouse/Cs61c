#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *x,*y;
    x=malloc(sizeof(int));
    *x=42;
    printf("x=%d\n",*x);

    y=x;
    *y=13;
    printf("x=%d, y=%d\n",*x,*y);
}
