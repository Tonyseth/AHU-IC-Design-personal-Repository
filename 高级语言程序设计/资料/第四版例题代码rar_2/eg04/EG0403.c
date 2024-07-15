// Program: EG0403.C
// Description: Input 10 digits, find the max and it's position.
#include <stdio.h>
#define SIZE 10
void main( void )
{
	int num[SIZE];
	int i, Max, MaxPos;

	printf("Enter 10 integers:");
	for( i = 0; i < SIZE; i ++ )
		scanf("%d", &num[i]);

	Max = num[0];
	MaxPos = 0;
	for( i = 1; i < SIZE; i ++ )
		if( Max < num[i] )
		{
			Max = num[i];
			MaxPos = i;
		}

	printf("Maximum value is %d\n", Max);
	printf("It¡¯s position is %d\n", MaxPos + 1);
}
