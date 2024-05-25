#include <stdio.h>
void main( void )
{
	int i, b, k=0;

	for( i = 0; i <= 5; i ++ )
	{
		b = i % 2;
		while( b -- >= 0 )
			k ++;
	}

	printf ("%d,%d\n", k, b);
	
}
