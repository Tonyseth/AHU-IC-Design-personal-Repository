#include <stdio.h>
void fun1(short a[3][3])
{
	short i, j, tmp;
	for(i=1; i<3; i++)
		for(j=0; j<i; j++)
		{
			tmp=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=tmp;
		}
}
void main( void )
{
	short matrix[][3]={ { 2, 4, 6},
						{ 9, 6, 3},
						{ 1, 3, 5}};
	short i, j;
	fun1(matrix);
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
			printf("%3d", matrix[i][j]);
		printf("\n");
	}
}