#include <stdio.h>
void main(void)
{
	char *p1="123", str[20]="abc", *p2=str;

	while( *p2 )
		p2 ++;
	while( *p2 = *p1 )
		p1 ++, p2 ++;

	puts( str );
}
