#include <stdio.h>
void main(void)
{
	/*******ERROR*******/
	int i, s, n, a[]={27, 56,123, 128, 154, 168, 178, 205, 362, 618};

	printf("input a number:\n");
	scanf("%d", &n);

	for( i = 0; i < 10; i ++ )
		/***ERROR***/
		if( n > a[i] )
		{
			for( s = 9; s >= i; s -- )
				a[s + 1] = a[s];
			break;
		}
	a[i] = n;

	for( i = 0; i <= 10; i ++ )
		printf("%d ", a[i]);
	printf("\n");
}
