#include <stdio.h>
void main(void)
{
	int a[20]={12, 32, 45, 6, 78, 88, 21, 34, 43, 46};
	int i=0, k=0;

	while( a[i] )
	{
		if( a[i] % 2 == 0 || a[i] %5 == 0 )
			k ++;
		i ++;
	}

	printf("%d,%d", k, i);
}
