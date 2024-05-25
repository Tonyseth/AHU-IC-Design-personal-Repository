// Program: EG0619.C
// Description: 外部变量与局部变量同名测试
#include <stdio.h>
int a=12, b=6;      			//定义外部变量a,b
int max( int a, int b )  		//a,b为外部变量
{
	return  a > b ? a : b;
}
void main( void )
{
	int a=30;

	printf("%d\n", max( a, b ));
}
