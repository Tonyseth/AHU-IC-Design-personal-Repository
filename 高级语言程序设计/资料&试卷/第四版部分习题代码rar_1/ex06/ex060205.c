#include <stdio.h>
double fun2( double x, double y, double z )
{
	return x > ( y > z ? y : z ) ? x : ( y > z ? y : z );
}

void main( void )
{
	double a=5.2, b=3.6, c=0.0;
	printf("%5.2lf\n", fun2( a, b, c ));
}
