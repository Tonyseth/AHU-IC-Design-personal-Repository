// Program: EG03-18.c
// Description: ��̴�ӡָ��������ͼ��
#include <stdio.h>
void main( void )
{ 
	char star='*', space=' ';               // �����ӡ����
	int i, j;                                  // �����ڡ���ѭ�����Ʊ���
	int num1, num2;                           // ��������Ʊ���

	for( i = 0; i < 7; i ++ )               // �п���
	{
		if( i < 4 )
			num1 = 3 + i, num2 = 7 - i * 2;// i<4�Ĺ���
		else
			num1 = 9 - i, num2 = i * 2 - 5;// i>=4�Ĺ���
		for( j = 0; j < num1; j ++ )
			putchar(space);                 // ���num1���ո�
		for( j = 0; j < num2; j ++ )
			putchar(star);                  // ���num2���Ǻ�
		printf("\n");                        // ����
	}
}
