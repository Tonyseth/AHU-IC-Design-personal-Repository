#include <stdio.h>
#include <string.h>
void main( int argc , char *argv[] )
{
	int i, len=0;

	for( i = 1; i < argc; i += 2 )
		len += strlen( argv[i] );

	printf("%5d\n", len);
} 