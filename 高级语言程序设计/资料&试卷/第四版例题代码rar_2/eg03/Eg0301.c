// Program: EG0301.C 
// Description: 输入圆的半径, 求对应圆的周长和面积 
#include <stdio.h>          					// 包含标准I/O库函数的说明 
#define PAI 3.141593     						// 定义符号常量PAI
void main( void )                   			// 主函数说明 
{
	double radius, perimeter, area ;   			// 局部变量说明 

	printf("请输入圆的半径:");    				// 显示输入提示文字 
	scanf("%lf", &radius);          			// 输入半径  

	perimeter = 2 * PAI * radius;   			// 求圆周长 
	area = PAI * radius * radius;   			// 求圆面积 

	printf("周长是%5.2lf, 面积是%5.2lf\n",
		perimeter, area);   					// 输出结果 
}

