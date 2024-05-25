#include <stdio.h>
void main(void)
{
    int i=3, *p1;
    int a[3]={15, 30, 45}, *p2;

    p1 = &i; p2 = a;
    p1 = p2 + 2;

    printf("%d,%d\n", *p1, *p2);
}
