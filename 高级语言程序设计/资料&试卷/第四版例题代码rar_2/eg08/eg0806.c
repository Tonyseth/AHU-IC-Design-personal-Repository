// Program: EG0806.C 
// Description: ����20���ַ���д��file3.txt�С�
#include <stdio.h>
#include <stdlib.h>
void main()
{
    FILE *fp1;                                 		 /* �����ļ���ָ����� */
    int i;
    char ch;

    if( ( fp1 = fopen( "file3.txt", "w" ) ) == NULL )/* ���ı��ļ�����д */
    {
        printf("File can not open!\n");
        exit( 0 );
    }

    for( i = 0; i < 20; i ++ )                    	 /* ѭ��20�� */
    {
        ch = getchar();    							 /* �Ӽ��̶�ȡ�ַ� */
        fputc( ch, fp1 );    						 /* д���ļ� */
    }

    fclose( fp1);                            		 /* �ر��ļ� */
}
