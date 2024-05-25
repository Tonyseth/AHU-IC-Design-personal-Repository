// Program: EG05-08.c 					    
// Description: 利用二维数组的行地址和列地址访问二维数组。 
#include <stdio.h> 
void main( void )               	
{
	int i, j, Num[2][3]; 

	printf("输入数据："); 
	for( i = 0; i < 2; i ++ )
		for( j = 0; j < 3; j ++ )
			scanf("%d", *(Num+i)+j);
		
	printf("输出数据：\n"); 
	for( i = 0; i < 2; i ++ )
	{
		for( j = 0; j < 3; j ++ )
			printf(" %d", *(Num[i]+j));
		printf("\n"); 
	}
}
