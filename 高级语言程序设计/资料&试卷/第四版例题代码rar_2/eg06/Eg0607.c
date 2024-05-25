// Program: EG0607.c
// Description: 通过函数输入10个整数，然后利用冒泡法从小到大排序，最后输出排序结果
#include <stdio.h>
void Input( int data[10], int size )
{
	//int i;

	printf("Input %d int: ", size);
	for( int i = 0; i < size; i ++ )
		scanf("%d", data + i);
}
void Sort( int data[], int size )
{
	int i, j, tmp;

	for( i = 0; i < size - 1; i ++ )
		for( j = 0; j < size - i - 1; j ++ )
			if( data[j] > data[j+1] )
				tmp = data[j], data[j] = data[j+1], data[j+1] = tmp;
}
void Print( int *data, int size )
{
	int  i;

	printf("The sorted number is :");
	for( i = 0; i < size; i ++ )
		printf(" %d", data[i]);
	printf("\n");
}
void main( void )
{
	int Num[10], n=10, *Ptr=Num;

	Input( Num, n );
	Sort( &Num[0], n );
	Print( Ptr, n );
}	