#include <stdio.h>
#define SIZE 10
void invert(int *p, int n)
{
	int i, tmp;
	for(i=0; i<n/2; i++)
	{
		tmp=p[i];
		p[i]=p[n-1-i];
		p[n-1-i]=tmp;
	}
}
void main( void )
{
	int Num[SIZE], k;
	printf("Enter 10 integers:\n");
	for(k=0; k<SIZE; k++)
		scanf("%d", Num+k);
	invert( Num, SIZE);
	printf("The 10 inverted number are:\n");
	for(k=0; k<SIZE; k++)
		printf("%5d", Num[k]);
	printf("\n");
}