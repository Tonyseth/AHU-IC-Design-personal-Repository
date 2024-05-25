#include <stdio.h>
void main(void)
{
    int num[]={1, 3, 5, 7}, s=1, i, *p=num;

    for( i = 0; i < 3; i ++ )
        s *= *(p + i);

    printf("%d\n", s);
} 


