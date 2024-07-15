#include <stdio.h>
int mycmp( char *p1, char *p2 )
{
	while( *p1 && *p2 && *p1 == *p2 )
		p1 ++, p2 ++;

	return *p1 - *p2;
}
void main(void)
{
	printf("%d\n", mycmp( "china", "chinese" ));
}
