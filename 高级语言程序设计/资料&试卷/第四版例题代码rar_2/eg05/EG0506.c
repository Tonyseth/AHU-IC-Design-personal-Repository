// Program: EG0506.c 
// Description: ����ָ��������ַ�������
#include <stdio.h> 
void main( void )
{
	char Str[20], *Ptr;

	printf("������һ�ַ���:");
	gets( Str );

	Ptr = Str;
	while( * Ptr != '\0' )
		Ptr ++; 

	printf("�ַ�������Ϊ%d\n", Ptr - Str);
}
