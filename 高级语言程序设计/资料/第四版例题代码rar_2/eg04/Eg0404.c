// Program: EG0404.C
// Description: 对10个整数按从小到大顺序进行选择法排序
#include <stdio.h>
#define SIZE 10
void main(void)
{
	int Num[SIZE]={12, 32, 28, 45, 67, 48, 18, 72, 90, 68};
	int Pos, tmp, i, j;

	printf("Normal numbers:");
	for( i = 0; i < SIZE; i ++ )
		printf("%d ", Num[i]);
	printf("\n");

	for( i = 0; i < SIZE - 1; i ++ )
	{
		Pos = i;
		for( j = i + 1; j < SIZE; j ++ )
			if( Num[j] < Num[Pos] )
				Pos = j;
		if( i != Pos )
			tmp = Num[i], Num[i] = Num[Pos], Num[Pos] = tmp;
	}

	printf("Sorted numbers:");
	for( i = 0; i < SIZE; i ++ )
		printf("%d ", Num[i]);
	printf("\n");
}
