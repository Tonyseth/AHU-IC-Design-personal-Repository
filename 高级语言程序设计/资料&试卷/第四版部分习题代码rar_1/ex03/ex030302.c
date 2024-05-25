#include <stdio.h>
void main (void)
{ 
	int num=123456, digit=0, t;

	printf("请输入一个自然数（如12345678）：");
	scanf("%d", &num);

	while( num )
	{
		t = num % 10;
		/***ERROR***/
		if( ! t % 2 )
			/*****ERROR*****/
			digit = digit + t * 10;
		num /= 10;
	}

	printf("%d\n", digit);
}
