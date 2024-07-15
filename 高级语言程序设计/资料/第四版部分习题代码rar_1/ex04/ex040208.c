##include <stdio.h>
void main( void )
{
	char  s[80]= "wereteye", c='e';
	int  i, j;

	for( i = j = 0; s[i] != '\0'; i ++ )
		if( s[i] != c )
			s[j ++] = s[i];
	s[j] = '\0';

	puts(s);
}
