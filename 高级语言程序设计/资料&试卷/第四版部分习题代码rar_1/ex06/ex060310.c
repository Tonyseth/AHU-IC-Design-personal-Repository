#include <stdio.h>
void increment( void )
{
	int x=0;
	x += 1;
	printf("%d", x);
}
void main( void )
{
	increment( );
	increment( );
	increment( );
} 