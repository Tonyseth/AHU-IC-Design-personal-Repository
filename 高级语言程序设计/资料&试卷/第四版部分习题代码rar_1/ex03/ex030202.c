#include <stdio.h>
void main (void)
{
	int num;

	for( num = 1; num < 80; ++ num )
		if( num % 5 == 0 && num %7 == 2 )
			printf("%d\n", num);
}
