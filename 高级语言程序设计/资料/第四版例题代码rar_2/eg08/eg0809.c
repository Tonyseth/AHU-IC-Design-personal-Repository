// Program: EG0809.C 
// Description: �ȳ��ַ������ļ���дʾ��
#include <stdio.h>
#include <stdlib.h>
void main( void )
{
	FILE *fp;
	int i;
	char str[4][13]={"���߲�������","����������","ҹ����������","����֪���١�"};

	if( ( fp = fopen( "file4.txt", "w" ) ) == NULL )	// ��ֻд���ı��ļ� 
	{
		printf("File can not open!\n");
		exit( 0 );
	}

	for( i = 0; i < 4; i ++ )							// ѭ������4����ʫ 
		fputs( str[i], fp );  							// ��������ʫд���ļ�

	fclose( fp );        		 						// �ر�fp��ָ����ļ� 

	if( ( fp = fopen( "file4.txt", "r" ) ) == NULL )	// ��ֻ�����ı��ļ� 
	{
		printf("File can not open!\n");
		exit( 0 );
	}

	for( i = 0; i < 4; i ++ )   	 					// ѭ����ȡ4����ʫ 
	{
		fgets( str[i], 13, fp); 	 					// ��ȡһ��12���ַ�
		puts( str[i] );            		 				// ���ַ��������ʾ 
	}

	fclose( fp );         		 						// �ر�fp��ָ����ļ� */
}
