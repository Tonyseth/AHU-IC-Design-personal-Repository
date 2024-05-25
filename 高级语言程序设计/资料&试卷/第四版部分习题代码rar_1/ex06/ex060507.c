#include <stdio.h>
//函数定义
float max(float m, float n)
{
	if (m>n)
		return m;
	else
		return n;
}
//宏定义
#define MAX(x, y) x>y?x:y
void main( void )
{
	float a, b, c;

	printf("input a, b, c:");//调用宏
	scanf("%f,%f,%f", &a, &b, &c);

	printf("MAX=%f\n", MAX(MAX(a, b), MAX(b, c)));//调用宏
	printf("max=%f\n", max(max(a, b), max(b, c)));//调用函数
}