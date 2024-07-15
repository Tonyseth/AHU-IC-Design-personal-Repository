#include <stdio.h>
void main(void)
{
    int a[]={1, 2, 3, 4, 5}, *p;

    p = a;
    *(p+2) += 2;

    printf("%d,%d\n", *p, *(p+2));
} 
