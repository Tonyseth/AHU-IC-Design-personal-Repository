/* Program: EG0104.c */
/* Description: 比较输入的四个浮点数, 打印最小数 */
#include <stdio.h>                 				// 包含标准I/O库函数的说明 

void main (void)                    			// 主函数说明 
{
	float first, second, third, fourth, min; 	// 局部变量说明 

    printf ("请输入四个浮点数:");            	// 显示输入提示文字 
    scanf ("%f,%f,%f,%f", &first, &second, &third, &fourth); // 输入数据

    min = first;
    if (second < min)                 			//求first、second中的小数
		min = second;
    if (third < min)                  			//求third、min中的小数
		min = third;
    if (fourth < min)               			//求fourth、min中的小数
		min = fourth;

    printf ("%f、%f、%f、%f中的最小数是%f\n",
		first, second, third, fourth, min);		// 输出结果
}
