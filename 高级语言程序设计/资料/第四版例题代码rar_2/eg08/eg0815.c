// Program: EG0815.C 
// Description: �����λ����fseek()ʹ��ʾ��
#include <stdio.h>
#include <stdlib.h>
void main( void )
{
     FILE *fp;
     int x, i;
     
     if ( ( fp = fopen( "file9.dat ", "wb+" ) ) == NULL )// �򿪶������ļ���д
     {
          printf("File can not open!\n");
          exit( 0 );
     }
     for ( i = 1; i <= 20; i ++ )                   // ѭ��20��
          fwrite( &i, sizeof( int ), 1, fp );   	// ��iд���ļ� 
     
     fseek(fp, 0L, SEEK_SET);                     // ��λ���ļ�ͷ 
     for ( i = 0; i < 3; i ++ )                   // ѭ����ȡ��1��3��5������
     {
          fread( &x, sizeof( int ), 1, fp );   	// �ӵ�ǰλ�ö�ȡ1������ 
          printf("%d ", x);                			// �����ȡ��1������ 
          fseek( fp, (long)sizeof(int), SEEK_CUR ); // ��λ����һ������
     }
     fseek( fp, (long)sizeof(int)*11, SEEK_SET ); // ��λ����12������ 
     fread( &x, sizeof( int ), 1, fp );   		// ��ȡ��12������ 
     printf("%d ", x);                				// �����ȡ�ĵ�12������ 
     fseek(fp, -1*(long)sizeof(int), SEEK_END); // ��λ����20������
     fread( &x, sizeof( int ), 1, fp );   		// ��ȡ��20������
     printf("%d ", x);                				// �����ȡ�ĵ�20������ 

     fclose( fp );                            		// �ر�fp��ָ����ļ� 
}



