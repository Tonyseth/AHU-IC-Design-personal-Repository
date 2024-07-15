#include <stdio.h>
//宏定义
#define SQU(x) (x)*(x)
void main( void )
{
	float a, b;
	printf("input a, b:");
	scanf("%f,%f", &a, &b);
	printf("SQU(a+b)=%f\n", SQU(a+b)); //调用宏
	printf("SQU(a-b)=%f\n", SQU(a-b)); //调用宏
}