// Program: EG0810.C 
// Description: ���ȳ��ַ������ļ���дʾ��
#include <stdio.h>
#include <stdlib.h>
void main( void )
{
    FILE *fp;
    int i;
    char str[81];

	if( ( fp = fopen( "file5.txt", "w" ) ) == NULL )	// ��ֻд���ı��ļ� 
	{
		printf("File can not open!\n");
		exit( 0 );
	}

	for( i = 0; i < 6; i ++ )							// ѭ������6�����Ȳ��ȵ��ַ��� 
	{
		fputs( gets( str ), fp );  						// ��������ַ���д��򿪵��ļ�
		fputs( "\n", fp );  							// д����ַ�����׷��һ�����з�
	}

	fclose( fp );        		 						// �ر�fp��ָ����ļ� 

	if( ( fp = fopen( "file5.txt", "r" ) ) == NULL )	// ��ֻ�����ı��ļ� 
	{
		printf("File can not open!\n");
		exit( 0 );
	}

	for( i = 0; i < 6; i ++ )   	 					// ѭ������6�����Ȳ��ȵ��ַ��� 
		puts( fgets( str, 81, fp) );; 	 				// ��ȡ1���ַ������������ʾ�� 

	fclose( fp );         		 						// �ر�fp��ָ����ļ� */
}
