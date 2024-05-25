#include <stdio.h>
void main( void )
{
	int a=1, b=2, c=3, d=4, m=1, n=1;
	if(!(( m = a > b ) && ( n = c > d )))
		printf("%d %d\n", m, n);
}