// Program: EG0312.C
// Description: 输出100-300以内所有既能被3整除，又能被7整除的数
#include <stdio.h>
void main( void )
{
	int i = 100;

	printf("100-300以内所有既能被3整除，又能被7整除的数有:\n");
	while( i <= 300 )
	{
		if( i % 3 == 0 && i % 7 == 0 )
			printf("%5d", i);
		i ++;
	}
	printf("\n");
}

