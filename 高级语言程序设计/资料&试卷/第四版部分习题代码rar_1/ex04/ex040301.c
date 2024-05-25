#include <stdio.h>
#define SIZE 10
void main(void)
{ 
	float Num[SIZE], tmp;
	int i, j;

	printf("Input 10 normal numbers: ");
	/******ERROR******/
	scanf("%f", &Num);

	for( i = 0; i < SIZE - 1; i ++)
	{
		for( j = 0; j < SIZE ¨C i - 1; j ++ )
			if( Num[j] > Num[j + 1] )
				tmp = Num[j], Num[j] = Num[j + 1], Num[j + 1]=tmp;
	}

	printf("Sorted numbers:");
	/******ERROR******/
	printf("%5.1f\n ", Num);

}
