// Program: EG0513.c 
// Description: ʹ���ַ�ָ��ɾ�������ַ������в��Ǻš�
#include <stdio.h> 
void main( void )               	
{
	char Str[80], *ps1, *ps2, *ps3;

	gets( Str );

	ps1 = Str; 
	// Ѱ�ҵ�һ�����Ǻ��ַ�
	while( *ps1 == '*' )
		ps1 ++;
	// Ѱ���ַ���������
	ps2 = ps3 = ps1; 
	while( *ps3 != '\0' )
		ps3 ++;
	// Ѱ��β����һ���Ǻ��ַ�
	ps3--;
	while( *ps3 == '*' )
		ps3 --;
	ps3++;

	// �����в����Ǻ��ַ�
	while( ps1 < ps3 )
	{
		if( *ps1 != '*' )
		{
			*ps2 = *ps1;
			++ ps2;
		}
		++ ps1;
	}
	// �´�ĩβ����β���Ǻż��ַ���������
	while( *ps2 = *ps3 )
		++ ps2, ++ ps3;

	puts( Str );
}
