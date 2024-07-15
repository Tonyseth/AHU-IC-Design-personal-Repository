#include <stdio.h>	// 包含标准I/O库函数说明 
void main(void)	// 主函数说明 
{
    float first, second, third, max;	// 局部变量说明 
    printf("请输入三个浮点数:");	// 显示输入提示文字 
    scanf("%f%f%f", &first, &second, &third);	// 输入数据
    
    max = first;
    if( second > max )	//求first、second中的大数
		max = second;
    if( third > max )	//求third、max中的大数
		max = third;
    printf("%f、%f、%f中的最大数是%f\n", first, second, third, max);	// 输出结果
}
