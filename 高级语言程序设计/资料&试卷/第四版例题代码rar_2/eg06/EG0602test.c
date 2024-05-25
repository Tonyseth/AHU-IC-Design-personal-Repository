// Program: EG0602test.c               	    
// Description: 测试Prime函数功能

#include <stdio.h>

int Prime( int Num ); // Prime函数的函数说明

void main( void )
{
	int i=2;

	while( i < 10)
	{
		printf("Prime(%d)=%d\n", i, Prime( i ));
		i ++;
	}
}
