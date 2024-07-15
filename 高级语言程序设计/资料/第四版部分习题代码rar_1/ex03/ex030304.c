#include <stdio.h>
void main (void)
{
	/***error***/
	int i=1, sum;

	do
	{								
		sum += i ;					
	}while ( ++ i <= 10 );
	/***error***/
}
