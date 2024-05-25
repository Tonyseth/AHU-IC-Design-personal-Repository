#include <stdio.h>
void add( int *x, int *y, int n )
{
	while( n-- )
		*x++ += *y++;
}
void main( void )
{
	int i=5;
	static int s1[]={2, 1, 0, 3, 2}, s2[5];

	add( s2, s1, 5 );

	while( i -- )
		printf("%2d", s2[i]);
} 