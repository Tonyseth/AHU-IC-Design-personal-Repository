// Program: EG0516.c 					    
// Description: ����n�����ʣ����䰴�ֵ�˳�������n�Ӽ������롣 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLenght 31 //������󳤶�
void main(void)
{
	char tmp[MaxLenght], **words;
	int i, j, k, n=5;

	printf("������n��");
	scanf( "%d", &n);
	if( (words = (char **) malloc( sizeof(char *)*n )) == NULL )
	{
		printf( "�ڴ����ʧ��\n" );
		return ;
	}
	
	for( i = 0; i < n; i ++ )
	{
		printf("�������%d�����ʣ�", i + 1);
		scanf( "%s", tmp);
		if( ( words[i] = (char *) malloc( sizeof(char)*( strlen(tmp) + 1 ) ) ) == NULL )
		{
			printf( "��%d�������ڴ����ʧ��\n", i + 1);
			return ;
		}
		strcpy( words[i], tmp );
	}
	
	for( i = 0; i < n - 1; i ++ )
	{
		k = i;
		for( j = i  +1; j < n; j ++)
			if( strcmp( words[k], words[j] )>0 )  
				k = j;
		if( k != i )
		{
			char *tmp;
			tmp = words[i], words[i] = words[k], words[k] = tmp;
		}
	}
	
	printf( "������\n");
	for( i = 0; i < n; i ++ )
		puts( words[i] );
	
	//for( i = 0; i < n; i ++ )
		//free( *(words+i) );
	free( words );
}
