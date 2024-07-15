#include <stdio.h>
#include <string.h>
void main( void )
{
	printf("%2d", strlen( "\\\048\48" ));
	printf("%2d", sizeof( "\\\048\48" ));

}