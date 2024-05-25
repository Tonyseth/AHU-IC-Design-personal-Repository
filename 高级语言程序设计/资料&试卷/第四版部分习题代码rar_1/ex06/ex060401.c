#include <stdio.h>
double factorial( int );
void main( void )
{
	int n;

	printf("Enter an integer: ");
	scanf("%d", &n);

	printf("\n\n%d!=%6.0lf\n\n", n, factorial( n ));
}
double factorial( int n )
{
    double result=1.0;

	/******ERROR******/
	while( n > 1 || n < 170 )
	//while( n > 1 && n < 170 )
		/*******ERROR*******/
		resul t*= (double)--n;
		//result *= (double)n--;

	return result;
}