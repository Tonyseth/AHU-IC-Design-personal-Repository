#include <stdio.h>
void main (void)
{
	int i, num;

	scanf("%d", &num);

	for( i = 2; i <= num / 2; ++ i )
		if( num % i == 0 )
			break;

	if( num >= i * 2 )
		printf("Yes\n");
	else
		printf("No\n");
}
