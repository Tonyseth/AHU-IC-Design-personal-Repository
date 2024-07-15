// Program: EG0316.c
// Description: 编程打印所有的“水仙花数”
#include <stdio.h>
void main( void )
{
	int hun, ten, ind, i;

	printf("水仙花数：");
	for( i = 100; i <= 999; i ++ )
	{
		ind = i % 10;       	//个位
		ten = i % 100 / 10;   	//十位
		hun = i / 100;       	//百位
		if( i == ind * ind * ind + ten * ten * ten + hun * hun * hun )
			printf("%5d", i);
	}
	printf("\n");
}
