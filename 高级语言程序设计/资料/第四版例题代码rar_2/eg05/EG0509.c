// Program: EG05-09.c 					    
// Description: 利用数组指针访问二维数组。 
#include <stdio.h> 
void main( void )               	
{
	int i, j, Num[][3]={{ 2,  4,  6},
	                    { 8, 10, 12},
	                    {14, 16, 18}};
	int (*Ptr)[3]=Num;	

	for( i = 0; i < 3; i ++, Ptr ++ )
	{
		for( j = 0; j < 3; j ++ )
			printf("%6d", (*Ptr)[j]);
		printf("\n"); 
	}
} 