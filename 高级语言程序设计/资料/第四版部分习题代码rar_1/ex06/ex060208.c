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
	funs3( s, s + strlen(s) - 1 );
}
char *fun5( unsigned n )
{
	int h, i=0; static char s[10];
	do
	{
		h = n % 16;
		s[ i ++ ] = ( h <= 9 ) ? h + '0' : h - 10 + 'a';
	}while( n /= 16 );
	fun3( s );
	return s;
}

void main( void )
{
	unsigned int num=123;
	printf("%s\n", fun5( num ));
}
