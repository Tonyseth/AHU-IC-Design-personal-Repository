// Program: EG0316.c
// Description: ��̴�ӡ���еġ�ˮ�ɻ�����
#include <stdio.h>
void main( void )
{
	int hun, ten, ind, i;

	printf("ˮ�ɻ�����");
	for( i = 100; i <= 999; i ++ )
	{
		ind = i % 10;       	//��λ
		ten = i % 100 / 10;   	//ʮλ
		hun = i / 100;       	//��λ
		if( i == ind * ind * ind + ten * ten * ten + hun * hun * hun )
			printf("%5d", i);
	}
	printf("\n");
}
