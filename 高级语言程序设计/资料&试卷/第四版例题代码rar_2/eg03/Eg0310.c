// Program: EG0310.C
// Description: �Ӽ�������n, ���㲢���1+2+��+n=?
#include <stdio.h>
void main( void )
{
    int n, i, sum;

    printf("Input n:");
    scanf("%d", &n);

    i = sum = 0;
    while( i < n )
            sum += ++ i;

    printf("1+2+��+%d=%d\n", n, sum);
}
