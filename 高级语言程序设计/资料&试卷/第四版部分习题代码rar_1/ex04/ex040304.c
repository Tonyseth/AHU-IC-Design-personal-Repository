#include <stdio.h>
#include <string.h>
void main( void )
{
	int c[256]={0};
	char s[1000]={0};
	int i, j, k;

	scanf("%s", s);

	for( i = 0; i < strlen(s); i ++ )
		c[s[i]] ++;
	j = -1;
	k = -1;
	for( i = 0; i < 256; i ++ )
		if( c[i] >= j )
		{
			j = c[i];
			k = i;
		}

	/******ERROR******/
	printf("%c\n", k);
}


