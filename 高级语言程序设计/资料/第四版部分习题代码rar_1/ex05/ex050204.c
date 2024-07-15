#include <stdio.h>
void main(void)
{
    int a[]={1, 3, 5, 7, 9}, *p, **k;

    p = a; k = &p;

    printf("%d,", *(p ++));
    printf("%d\n", **k);
}

