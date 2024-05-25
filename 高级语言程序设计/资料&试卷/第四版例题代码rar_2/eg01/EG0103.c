/* Program: EG0103.c */
/* Description: Comparing first and second, see which is the bigger. */
#include <stdio.h>                        // 包含标准I/O库函数的说明 
void main( void )                         // 主函数说明 
{
	int first, second, max;               // 局部变量说明 

	printf("请输入两个整数:");            // 显示输入提示文字 
	scanf("%d,%d", &first, &second);      // 从键盘输入数据存入变量 

	max = first;                          // 将first作为初值赋给max
	if( second > max )                    // 比较max和second
		max = second;                     // 将较大的second值赋给max

	printf("第一个数是%d\n", first);      // 输出结果 
	printf("第二个数是%d\n", second);
	printf("大数是%d\n", max);
}

