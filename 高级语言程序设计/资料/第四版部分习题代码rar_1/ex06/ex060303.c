#include <stdio.h>
void ss( char *s, char t )
{
	while( *s )
	{
		if( *s == t )
			*s = t - 'a' + 'A';
		s ++;
	}
}
void main(void)
{
	char str1[100]="abcddfefdbd", c='d';

	ss( str1, c );

	printf("%s\n", str1);
}
