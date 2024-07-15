#include <stdio.h>
#include <string.h>
void main(void)
{
	char str[30];

	strcpy( &str[0], "CHINA" );
	strcpy( &str[1], "DEFINE" );
	strcpy( &str[2], "ARM" );

	printf("%s\n", str);
}
