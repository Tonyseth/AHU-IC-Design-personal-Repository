// Program: EG03-14.C 
// Description: 利用泰勒公式编程求sin(x)=?
#include <stdio.h>
void main( void )
{
	double s=0, t, x;
	int i=1, flag;

	printf("please input x:");
	scanf("%lf", &x);

	if ( x >= 0 )
		t = x, flag = 1;
	else
		t = -x, flag = -1;
	do
	{
		s += flag * t;
		i += 2;
		t *= x * x / ( i - 1 ) / i;
		flag = -flag;
	} while ( t >= 1e-6 );

	printf("sin(%7.5lf)=%6.4lf\n", x, s);
}
