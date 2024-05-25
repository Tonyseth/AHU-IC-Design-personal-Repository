// Program: EG0505.c 
// Description: 利用指针自增、自减访问数组。
#include <stdio.h>
void main( void )               	
{
	int Num[5], i, *Ptr=Num;

	printf("顺序输入5个整数："); 
	for( i = 0; i < 5; i ++, Ptr ++ )
		scanf("%d", Ptr);

	printf("逆序打印Num："); 
	for( i = 0; Ptr --, i < 5; i ++ )
		printf(" %d", *Ptr); 
	printf("\n");  
}
