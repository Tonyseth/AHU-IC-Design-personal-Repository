// Program: EG0402a.C
// Description: 输入一个八进制数123转成二进制数101 0011
#include <stdio.h>
void main( void )
{    
    int num;
    int digit[8], i, j;

    scanf("%o", &num);

    for(i = 0; num != 0; i ++)
    {
		digit[i] = num % 2;
		num /= 2;
    }

    for(j = i ; j >= 0; j --)
		printf("%d", digit[j]);
    printf("\n");
}