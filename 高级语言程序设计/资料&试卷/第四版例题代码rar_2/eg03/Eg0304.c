// Program: EG0304.C
// Description: 输入一个五位正整数, 要求顺序打印出各位数字。
#include <stdio.h>

void main (void)
{
	int num; 
	int a, b, c, d, e;

	printf ("Input a integer number (10000-99999):");
	scanf ("%d", &num);

	if (num > 99999 || num < 10000)
		printf ("Error input!\n");
	else
	{
		e = num % 10;  num /= 10;
		d = num % 10;  num /= 10;
		c = num % 10;  num /= 10;
		b = num % 10;  num /= 10;
		a = num;
		printf ("Each digit is %2d%2d%2d%2d%2d\n", a, b, c, d, e);
	}
}
