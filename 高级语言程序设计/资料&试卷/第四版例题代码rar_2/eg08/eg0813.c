// Program: EG0813.C 
// Description: ��ʽ���ݵ��ļ���дʾ��
#include <stdio.h>
#include <stdlib.h>
void main( void )
{
     FILE *fp;
     char ch, ch0, str[81], str0[81];
     int i, i0;
     double r, r0;

     if( ( fp = fopen( "file8.txt", "w" ) ) == NULL )    // ��ֻд�ı��ļ� 
     {
          printf("File can not open!\n");
          exit( 0 );
     }
     scanf("%c", &ch);                       	// �Ӽ��̶�ȡ1���ַ� 
     scanf("%d,", &i);              			// �Ӽ��̶�ȡ2�������� 
     scanf("%lf,", &r);                  		// �Ӽ��̶�ȡ5��˫����ʵ�� 
     scanf("%s", str);                   		// �Ӽ��̶�ȡ6���ַ��� 
     // ��1���ַ���1��������1��ʵ����1���ַ�����ָ����ʽд��fpָ����ļ� 
     fprintf( fp, "%c%d,%f,%s\n", ch, i, r, str );
     fclose( fp );                       		// �ر�fp��ָ����ļ� 

     if( ( fp = fopen( "file8.txt", "r" ) ) == NULL )    // ��ֻд�ı��ļ� 
     {
          printf("File can not open!\n");
          exit( 0 );
     }
     fscanf( fp,"%c", &ch0 );              	// ���ļ��ж�ȡ1���ַ� 
     fscanf( fp,"%d,", &i0 );              	// ���ļ��ж�ȡ1������ 
     fscanf( fp,"%lf,", &r0 );             	// ���ļ��ж�ȡ1��ʵ�� 
     fscanf( fp, "%s", str0 );      		// ���ļ��ж�ȡ1���ַ��� 
	     // ������ļ��ж�ȡ������ 
     printf("%c\n%d\n%f\n%s\n", ch0, i0, r0, str0);
     fclose( fp );                        		// �ر�fp��ָ����ļ� 
}

