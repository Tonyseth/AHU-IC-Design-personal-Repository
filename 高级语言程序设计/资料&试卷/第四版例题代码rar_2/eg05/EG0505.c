// Program: EG0505.c 
// Description: ����ָ���������Լ��������顣
#include <stdio.h>
void main( void )               	
{
	int Num[5], i, *Ptr=Num;

	printf("˳������5��������"); 
	for( i = 0; i < 5; i ++, Ptr ++ )
		scanf("%d", Ptr);

	printf("�����ӡNum��"); 
	for( i = 0; Ptr --, i < 5; i ++ )
		printf(" %d", *Ptr); 
	printf("\n");  
}
