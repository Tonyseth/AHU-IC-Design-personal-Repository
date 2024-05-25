#include <stdio.h>
#define SIZE 10
void main(void )
{
	int x[SIZE], i, pos;

	printf("Enter %d integers:\n", SIZE);
	for( i = 0; i < SIZE; i ++ )
		/******ERROR******/
		printf("%d:", i);
		scanf("%d", &x[i]);

	pos = 0;
	for( i = 0; i < SIZE; i ++ )
		/******ERROR******/
		if( pos > x[i] )
			pos = i;

	printf("Minimum value is %d, No%d.\n", x[pos], pos + 1);
}

