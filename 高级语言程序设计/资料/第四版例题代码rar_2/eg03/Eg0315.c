// Program: EG0315.C
// Description: 用二分法求一元三次方程f(x)=0的根
#include <stdio.h>
#include <math.h>
void main( void )
{
	double x0, x1, x2, y0, y1, y2;

	do
	{
		printf("Please input x1,x2 :");
		scanf("%lf,%lf", &x1, &x2);
		y1 = 3*x1*x1*x1 - 2*x1*x1 + 5*x1 - 16;
		y2 = 3*x2*x2*x2 - 2*x2*x2 + 5*x2 - 16;
	}while( y1 * y2 > 0 );

	do
	{
		x0 = ( x1 + x2 ) / 2;
		y0 = 3*x0*x0*x0 - 2*x0*x0 + 5*x0 - 16;
		if( y0 * y1 <0 )
			x2 = x0;
		else
			x1 = x0;
	} while ( fabs(y0) >= 1e-6 );

	printf("The root is %lf\n", x0);
}
