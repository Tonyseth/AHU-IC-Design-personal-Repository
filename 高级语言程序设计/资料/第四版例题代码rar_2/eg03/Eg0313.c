// Program: EG0313.C
// Description: 利用迭代法求a的平方根
#include <stdio.h>
#include <math.h>
void main( void )
{
	double a, x0, x1;

	printf("Input a:");
	scanf("%lf", &a);

	x1 = a / 2;
	do
	{
		x0 = x1;
		x1 = ( x0 + a / x0 ) / 2;
	} while( fabs( x0 - x1 ) >= 1e-6 );

	printf("The square root of %5.2f is %5.2f\n", a, x1);

}
