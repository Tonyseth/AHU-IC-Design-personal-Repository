// Program: EG0312.C
// Description: ���100-300�������м��ܱ�3���������ܱ�7��������
#include <stdio.h>
void main( void )
{
	int i = 100;

	printf("100-300�������м��ܱ�3���������ܱ�7����������:\n");
	while( i <= 300 )
	{
		if( i % 3 == 0 && i % 7 == 0 )
			printf("%5d", i);
		i ++;
	}
	printf("\n");
}

