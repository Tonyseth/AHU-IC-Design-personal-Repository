// Program: EG0603.C                       
// Description: ����VC��ʵ�����˳�� 
#include <stdio.h>
void fun( int a, int b)
{
 	printf("���������У�a=%d, b=%d\n", a, b );
}

void main( void )
{
	int i=8;
	fun( i += 3, i -= 2 );
}

