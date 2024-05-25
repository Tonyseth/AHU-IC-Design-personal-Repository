#include <stdio.h>
int fun1( char *str )
{
	char *ptr=str;

	while( *ptr++ );

	return ptr - str - 1;
}
void main( void )
{
	printf("%d\n", fun1( "\\\048\48" ));
}
