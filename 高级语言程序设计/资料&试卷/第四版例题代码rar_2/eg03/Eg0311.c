// Program: EG0311.C
// Description: 利用格里高利公式编程求π的近似值
#include <stdio.h>
void main( void )
{
	double pi = 0, t = 1;
	int i = 1;

	while( t >1e-6 )
	{
		if( i % 2 )
			pi += t;
		else
			pi += - t;
		i ++ ;
		t = 1.0 / (2 * i - 1);
	}
	//if( i%2 )
	//	pi += t;
	//else
	//	pi += - t;

	printf("pi = %10.8lf\n", pi * 4);
}
