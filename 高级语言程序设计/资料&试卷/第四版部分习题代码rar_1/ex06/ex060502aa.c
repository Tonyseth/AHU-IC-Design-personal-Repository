#include <stdio.h>
int prime( int i )
{
	int j;
	for(j=2; j<i; j++)
		if(!(i%j))
			return 0;
	return 1;
}
void main( void )
{
	int i=2, n, count=0;
	printf("Input n(2~100):");
	scanf("%d",&n);
	while(i<=n)
	{
		if(prime(i))
		{
			printf("%d ",i);
			count++;
		}
		i++;
	}
	printf("\nprime num is %d.\n", count);
}