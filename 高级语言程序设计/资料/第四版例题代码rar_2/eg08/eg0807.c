// Program: EG0807.C 
// Description: ����file3.txtǰ10���ַ���
#include <stdio.h>
#include <stdlib.h>
void main()
{
    FILE *fp1;                                 		 /* �����ļ���ָ����� */
    int i;
    char ch;

    if( ( fp1 = fopen( "file3.txt", "r" ) ) == NULL )/* ���ı��ļ����ڶ� */
    {
        printf("File can not open!\n");
        exit( 0 );
    }

    for( i = 0; i < 10; i ++ )                    	 /* ѭ��10�� */
    {
        ch = fgetc( fp1 );        					 /* ���ļ��ж�ȡ1���ַ��������ch */
        putchar( ch );    							 /* ������ch���ַ��������ʾ�� */
    }

    fclose( fp1);                            		 /* �ر��ļ� */
}
