// Program: EG0407.C
// Description: 在按从小到大顺序排好序的9个浮点数中插入输入的数
#include <stdio.h>
#define SIZE 10
void main( void )
{
	float Num[SIZE]={12, 22, 33, 36, 48, 56, 68, 72, 81};
	int i; 
	float tmp;

	printf("Normal numbers:");
	for( i = 0; i < SIZE - 1; i ++ )
		printf("%3.0f", Num[i]);
	printf("\n");

	printf("Input new number:");
	scanf("%f", &Num[SIZE - 1]);
	for( i = 0; i < SIZE - 1; i ++ )
		if( Num[i] > Num[SIZE - 1] )
			tmp = Num[i], Num[i] = Num[SIZE - 1], Num[SIZE - 1]=tmp;

	printf("New numbers:");
	for( i = 0; i < SIZE; i ++ )
		printf("%3.0f", Num[i]);
	printf("\n");
}
