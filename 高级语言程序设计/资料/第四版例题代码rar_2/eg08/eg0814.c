// Program: EG0814.C 
// Description: �ļ�ͷ��λ����rewind()ʹ��ʾ��
#include <stdio.h>
#include <stdlib.h>
void main( void )
{
     FILE *fp;                                             // �����ļ���ָ����� 
     int i;
     
     if ( ( fp = fopen( "file3.txt", "w+" ) ) == NULL )// ���ı��ļ����ڶ�д
     {
          printf("File can not open!\n");
          exit( 0 );
     }
     
     for ( i = 0; i < 20; i ++ )                       // ѭ��20��
          fputc( fgetc( stdin ), fp );           		// �Ӽ��̶�ȡ�ַ�д���ļ� 

     rewind( fp );                           			// ���ڲ�ָ������ָ���ļ�ͷ 
     for ( i = 0; i < 10; i ++ )                       // ѭ��10��
          fputc( fgetc( fp ), stdout);  				// ���ļ��ж�ȡ1���ַ���ʾ 

     fclose( fp );                                         // �ر��ļ� 
}


