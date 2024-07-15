// Program: EG0603.C                       
// Description: 测试VC的实参求解顺序 
#include <stdio.h>
void fun( int a, int b)
{
 	printf("函数调用中：a=%d, b=%d\n", a, b );
}

void main( void )
{
	int i=8;
	fun( i += 3, i -= 2 );
}

