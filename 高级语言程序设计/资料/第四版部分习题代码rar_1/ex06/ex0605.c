#include <stdio.h>
#define NUM 10
void invert(int *p, int n)
{
	int i,tem;
	for(i=0;i<n/2;i++)
	{
		tem=p[i];
		p[i]=p[n-1-i];
		p[n-1-i]=tem;
	}
}
void main( void )
{
	int x[NUM], k;
	printf("Enter 10 integers:\n");
	for(k=0; k<NUM; k++)
		scanf("%d", x+k);
	invert( x, NUM);
	printf("The 10 inverted number are:\n");
	for(k=0; k<NUM; k++)
		printf("%5d", x[k]);
		printf("\n");
}
