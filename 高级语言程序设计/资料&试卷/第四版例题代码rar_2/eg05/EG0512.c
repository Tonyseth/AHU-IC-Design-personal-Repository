// Program: EG0512.c 
// Description: ʹ���ַ�ָ��ɾ�������ַ�����ǰ���Ǻš�
#include <stdio.h> 
#include <string.h>
void main( void )               	
{
	char Str[80], *ps1, *ps2;

	gets( Str );

	ps1 = ps2 = Str; 
	// Ѱ�ҵ�һ�����Ǻ��ַ�
	while( *ps1 == '*' )
		ps1 ++;
	// ����ʣ���ַ�
	while( *ps1 != '\0' )
	{
		*ps2 = *ps1;
		++ ps1;
		++ ps2;
	}
	// �´�ĩβ����ַ���������
	*ps2 = '\0';

	puts( Str );
}
