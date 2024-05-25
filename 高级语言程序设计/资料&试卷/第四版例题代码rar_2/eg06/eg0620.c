// Program: EG0620.C
// Description: 测试局部静态变量
#include <stdio.h>
int fun( int a )
{
	auto int b=0;
	static int c=3;

	b = b + 1;
	c = c + 1;

	return a + b + c;
}
void main( void )
{
	int a=2, i;

	for( i = 0; i < 3; i ++)
		printf("%2d", fun(a));
	printf("\n");
}

