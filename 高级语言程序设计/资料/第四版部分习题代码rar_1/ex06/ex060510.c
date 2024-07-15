#include <stdio.h>
#include <malloc.h>
void sort(int *num, int n)
{
	int i, j, k, tmp;
	for(i=0; i<n-1; i++)
	{
		k=i;
		for(j=i+1; j<n; j++)
			if(num[j]<num[k])
				k=j;
			if (k!=i)
			{
				tmp=num[i];
				num[i]=num[k];
				num[k]=tmp;
			}
	}
}
void main( void ) 
{
	int i, n, *Num;
	printf("input n:");
	scanf("%d", &n);
	Num=(int *)malloc(sizeof(int)*n);
	printf("input num:");
	for(i=0; i<n; i++)
		scanf("%d", Num+i);
	sort( Num, n);
	printf("Sorted num:");
	for(i=0; i<n; i++)
		printf("%3d", Num[i]);
	printf("\n");
}