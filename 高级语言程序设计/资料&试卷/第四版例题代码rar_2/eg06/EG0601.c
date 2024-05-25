// Program: EG0601.c               	    
// Description: 函数设计示范：输入m、n计算组合C(m,n)

#include <stdio.h>

int combination( int m, int n ); // 组合函数的函数说明

void main( void )
{
	int m, n;

	scanf("%d,%d", &m, &n);
	
	printf("C(%d,%d)=%d\n", m, n, combination( m, n ));
}
