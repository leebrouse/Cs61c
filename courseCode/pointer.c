#include <stdio.h>
void IncrementPtr(int **p);
int main(void)
{    
    int A[3]={50,60,70};
    int *q=A;
    IncrementPtr(&q);
    printf("*q = %d\n",*q);
}

void IncrementPtr(int **p){
    *p=*p+1;
}

