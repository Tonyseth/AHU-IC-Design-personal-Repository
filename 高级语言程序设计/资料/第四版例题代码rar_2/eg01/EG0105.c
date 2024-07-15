/* Program: EG0105.c */
/* Description: 比较输入的三个整数, 打印最大数. */
#include <stdio.h>	// 包含标准I/O库函数的说明
int big( int num1, int num2 )	// 子函数说明
{
    int max;					// 局部变量说明

    max=num1; 
    if(num2>max)				// 求大数
        max=num2;

    return max;					// 返回结果
}
void main( void )				// 主函数说明
{
    int first, second, third, max;	// 局部变量说明

    printf("请输入三个整数:");		// 显示输入提示文字 
    scanf("%d,%d,%d", &first, &second, &third);	// 输入数据

    max = big( first, second );		// 求first、second中的大数
    max = big( third , max );		// 求third、max中的大数

    printf("%d、%d、%d中的最大数是%d \n",
             first, second, third, max);		// 输出结果 
}
