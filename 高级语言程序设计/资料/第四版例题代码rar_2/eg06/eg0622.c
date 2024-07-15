// Program: EG0622.C
// Description: 测试不带参数的宏定义
#include <stdio.h>
#define  PI  3.1415926
#define  R  3 + 2
void main( void )
{
	printf("PI*R*R=%f\n", PI * R * R);
}

