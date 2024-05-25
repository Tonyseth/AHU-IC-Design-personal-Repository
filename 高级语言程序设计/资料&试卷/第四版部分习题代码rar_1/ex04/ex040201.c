#include <stdio.h>
void main(void)
{
	int i, a[10];

	for( i = 0; i < 10; i ++ )
		a[i] = i;

	for( i = 9; i >= 0; i-- )
		printf("%d", a[i]);
}
