// Program: EG0602test.c               	    
// Description: ����Prime��������

#include <stdio.h>

int Prime( int Num ); // Prime�����ĺ���˵��

void main( void )
{
	int i=2;

	while( i < 10)
	{
		printf("Prime(%d)=%d\n", i, Prime( i ));
		i ++;
	}
}
