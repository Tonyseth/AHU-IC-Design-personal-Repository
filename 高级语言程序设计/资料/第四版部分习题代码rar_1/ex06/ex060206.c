#include <stdio.h>
#include <string.h>
void funs3( char *s, char *t )
{
	char c;

	if( s < t )
		c = *s, *s = *t, *t = c, funs3( ++ s, -- t );
}
void fun3( char *s )
{
	funs3( s, s  +strlen(s) - 1 );
}

void main( void )
{
	char str[]="abcdef";

	fun3( str );

	printf("%s\n", str);
}
