#include <stdio.h>
double fun( double x, int n )
{
	int i; double y=1;
	for( i = 1; i <= n; i ++ )
		y = y * x;
	return y;
}

void main( void )
{
	double x=1, y=2;
	printf("%7.2lf\n", fun( x, 3 )-fun( x + y, 3 ));
} 