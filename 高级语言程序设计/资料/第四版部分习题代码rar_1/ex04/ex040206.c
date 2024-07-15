#include <stdio.h>
void main(void)
{
	char s[]="kjihgfedcba";
	int  p=9;

	while( s[p] != 'i' )
		printf("%c", s[p--]);
}
