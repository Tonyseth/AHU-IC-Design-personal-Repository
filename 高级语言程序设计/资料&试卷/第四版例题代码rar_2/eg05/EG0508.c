// Program: EG05-08.c 					    
// Description: ���ö�ά������е�ַ���е�ַ���ʶ�ά���顣 
#include <stdio.h> 
void main( void )               	
{
	int i, j, Num[2][3]; 

	printf("�������ݣ�"); 
	for( i = 0; i < 2; i ++ )
		for( j = 0; j < 3; j ++ )
			scanf("%d", *(Num+i)+j);
		
	printf("������ݣ�\n"); 
	for( i = 0; i < 2; i ++ )
	{
		for( j = 0; j < 3; j ++ )
			printf(" %d", *(Num[i]+j));
		printf("\n"); 
	}
}
