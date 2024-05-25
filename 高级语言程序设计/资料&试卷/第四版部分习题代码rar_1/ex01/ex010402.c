#include <stdio.h>	// 包含标准I/O库函数说明 
int small(int num1, int num2) 	// 子函数说明
{
	int min=num1; 	// 局部变量说明
	if( min > num2 )	// 求较小数 
		min = num2;
	return min;	// 返回结果 
}
void main(void)	// 主函数说明
{ 
    int first, second, third, min;	// 局部变量说明 
    printf("请输入三个整数: ");	// 显示输入提示文字 
    scanf("%d%d%d", &first, &second, &third);	// 输入数据 
    min = small( first, second );	// 求first、second中的较小数
    min = small( third, min );	// 求third、min中的较小数
    printf("%d、%d、%d中的最小数是%d\n",
        first, second, third, min);	// 输出结果 
}
