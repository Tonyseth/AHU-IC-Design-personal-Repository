#include <stdio.h>
#define N 3
int fun( int (*a)[N] )
{
	int row, col, max, min;

	for( row = 0; row < N; row ++ )
	{
		for( max = a[row][0], col = 1; col < N; col ++ )
			if( max < a[row][col] )
				max = a[row][col];
		if( row == 0 )
			min = max;
		else
			if( min > max )
				min = max ;
	}

	return min;
}
void main( void )
{
    int Num[3][3]= {{ 32,  22, 78},
					{ 12,  56, 32},
					{ 73, 122, 65}};

    printf("The min is %d\n", fun( Num ));
}
