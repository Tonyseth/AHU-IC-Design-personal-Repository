// Program: EG0601.c               	    
// Description: �������ʾ��������m��n�������C(m,n)

#include <stdio.h>

int combination( int m, int n ); // ��Ϻ����ĺ���˵��

void main( void )
{
	int m, n;

	scanf("%d,%d", &m, &n);
	
	printf("C(%d,%d)=%d\n", m, n, combination( m, n ));
}
