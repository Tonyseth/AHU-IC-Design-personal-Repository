// Program: EG0621.C
// Description: 用局部静态变量编程打印1～10的阶乘数值
#include <stdio.h>

int fac( int n )
{
	static int f=1;

	return f *= n;
}

void main( void )
{
	int i;

	for( i = 1; i < 11; i ++)
		printf("%d!=%d\n", i, fac( i ));
}

