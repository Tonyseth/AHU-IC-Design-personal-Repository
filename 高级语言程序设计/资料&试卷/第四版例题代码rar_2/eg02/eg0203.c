// Program: EG0203.C 
// Description: 演示符号常量的使用
#include <stdio.h>
#define PI 3.14159
void main( void )
{
	printf("半径：%f\n", 1.0);
	printf("圆周长：%f\n", 2 * PI * 1.0);
	printf("圆面积：%f\n", PI * 1.0 * 1.0);
}
