// Program: EG0605.C                       
// Description: ���ú���������������
#include <stdio.h>
void swap( int *a, int *b )
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void main( void )
{
	int a=15, b=5;
	printf("��������ǰ, a=%d, b=%d\n", a, b);
	if( a > b )
		swap( &a, &b );
	printf("�������ú�, a=%d, b=%d\n", a, b);
}

