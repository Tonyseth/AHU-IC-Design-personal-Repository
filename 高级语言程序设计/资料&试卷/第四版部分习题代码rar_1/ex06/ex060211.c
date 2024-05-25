#include <stdio.h>
#include <stdio.h>
void proc(int i)
{
	int j, k;

	for( j = 0; j <= 7 - i; j ++)
		printf(" ");
	for( k = 0; k < 2 * i + 1; k ++ )	
		printf("*");
	printf("\n");
}
void main(void)
{
	int i;

	for( i = 0; i < 3; i ++ )
		proc( i );
	for( i = 3; i >= 0; i --)
		proc( i );
}