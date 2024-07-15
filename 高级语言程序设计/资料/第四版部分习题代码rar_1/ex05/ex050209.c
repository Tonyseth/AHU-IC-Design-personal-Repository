#include <stdio.h>
void main(void)
{
	char *p="1A2B3C4D";

	while( *p != '4' )
		printf("%c", *(p ++) + 1);
}
