// Program: EG0416.C 
// Description: ��̽�10��ͬѧ�������Ϳ��Գɼ���������������
#include <stdio.h>
#include <string.h>
void main( void )
{
    char Names[10][10]={"����", "����", "��һ", "����", "Ǯ��", "����", "����",
                        "���","����","֣��"}, NameTmp[10];

	int Scores[10]={95, 74, 83, 90, 66, 89, 70, 92, 73, 86}, ScoreTmp;
    unsigned int i, j; 
 
	for( i = 0; i < 10; i ++ )
		for( j = 0; j < 10 - i - 1; j ++ )
			if( strcmp(Names[j], Names[j + 1]) > 0 )
			{
				strcpy( NameTmp, Names[j] );
				strcpy( Names[j], Names[j + 1] );
				strcpy( Names[j + 1], NameTmp );
				ScoreTmp = Scores[j];
				Scores[j] = Scores[j + 1];
				Scores[j + 1] = ScoreTmp;
			}

	printf("The shorted data is :\n");
	for( i = 0; i < 10; i ++ )
		printf("%s\t%d\n", Names[i], Scores[i]);
}
