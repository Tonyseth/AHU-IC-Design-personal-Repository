// Program: EG0321.c
// Description: ��̽�������������ֽ�������ӵ����˻�
#include <stdio.h>
void main( void )
{
	unsigned int n, i=2;

	printf("Please input a integer number:");
	scanf("%u", &n);

	printf("%u=", n);
	do
	{
		if( i >= n )
		{
			printf("%u\n", n);
			break;
		}
		if( n % i == 0 )
		{
			printf("%u*", i);
			n = n / i;
		}
		else
			i ++;
	} while( i <= n );

}
