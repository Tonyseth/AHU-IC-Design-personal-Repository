// Program: EG0808.C 
// Description: �����ı��ļ�
#include <stdio.h>
#include <stdlib.h>
void main( void )
{
	char fname1[81], fname2[81]; 		// �����ַ�����������������ļ���
	FILE *fp1, *fp2;             			// �����ļ���ָ���������ָ�������ļ�

	scanf("%s%s", fname1, fname2);		// ����Դ�ļ�����Ŀ���ļ���
	if( ( ( fp1 = fopen( fname1, "r" ) ) == NULL ) )// ��ֻ���ı�Դ�ļ�
	{
		printf("File can not open!\n");
		exit( 0 );
	}
	if( ( ( fp2 = fopen( fname2, "w" ) ) == NULL ) )// ��ֻд�ı�Ŀ���ļ�
	{
		printf("File can not open!\n");
		exit( 0 );
	}

	while( !feof( fp1 ) )        		//fp1��δָ���ļ�β
		fputc( fgetc( fp1 ), fp2 );		//��Դ�ļ���1���ַ�д��Ŀ���ļ���

	fclose( fp1 );           		    	//�ر�fp1��ָ���Դ�ļ�
	fclose( fp2 );         		      	//�ر�fp2��ָ���Ŀ���ļ�
}
