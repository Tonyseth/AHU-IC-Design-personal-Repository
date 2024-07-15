// Program: EG0305.C 
// Description: 从键盘输入一个年份, 要求判断出它是否是平年 
#include <stdio.h>

void main (void)
{
	int year; 

	printf ("请输入一个年份:");
	scanf ("%d", &year);

	if (((year % 100 != 0) && (year % 4 != 0)) ||
		((year % 100 == 0) && (year % 400 != 0)))
		printf ("%d 是平年。\n", year);
	else
		printf ("%d 不是平年。\n", year);
}
