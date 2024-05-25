// Program: EG0406.C
// Description: 按从大到小顺序排好序的15个整数中折半查找输入的数x。
#include <stdio.h>
#define SIZE 15
void main( void )
{
	int Num[SIZE]={81, 72, 68, 66, 56, 48, 36, 33, 22, 12, 10, 9, 6, 3, 1};
	int Begin=0, End=SIZE-1, Mid, x;

	printf("Input x:");
	scanf("%d", &x);

	while( Begin <= End )
	{
		Mid = ( Begin + End ) / 2;
		if( x == Num[Mid] )
		{
			printf("It's position is %d \n", Mid + 1);
			break;
		}
		if( x < Num[Mid] )
			Begin = Mid + 1;
		else
			End = Mid - 1;
	}

	if( Begin > End )
		printf("Cann't find it\n");
}
