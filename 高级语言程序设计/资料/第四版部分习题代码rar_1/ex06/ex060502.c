#include <stdio.h>
int prime( int i )
{
	int j;
	for(j=2; j<i; j++)
		if(i%j==0)
			return 0;
	return i;
}
void main( void )
{
	int i=2, n, sum=0;
	printf("Input n(2~100):");
	scanf("%d", &n);
	while(i<=n)
	{
		sum=sum+prime(i);
		i++;
	}
	printf("sum=%d\n", sum);
}