// Program: EG0811.C 
// Description: ����10��������ʹ��fwrite��������洢��file6.dat��
#include <stdio.h>
#include <stdlib.h>
void main( void )
{
    FILE *fp;
    int num[6], i;
    for( i = 0; i < 6; i ++ )                // ����6������
        scanf("%d", &num[i]);                

    if( ( fp = fopen( "file6.dat" , "wb" ) ) == NULL )  //  ��ֻд�������ļ� 
    {
        printf("File can not open!\n");
        exit( 0 );
    }

	// �������num�����е�6������д��fpָ����ļ���
    fwrite( num, sizeof( int ), 6, fp ); 

    fclose( fp );                        // �ر�fp��ָ����ļ� 
}
