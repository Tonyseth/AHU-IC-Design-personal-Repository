#include <stdio.h>
void fun4( char *f, char *t )
{
	for(; *f != '\0'; f ++, t ++ )
		*t = *f;
	*t = '\0';
}

void main( void )
{
	char str1[10], *str2="abcdef";

	fun4( str2, str1 );

	printf("%s\n", str1);
}
