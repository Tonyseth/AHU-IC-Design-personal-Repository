// Program: EG0705.C 
// Description: ���ҳɼ�����ͬѧ��Ϣ
#include <stdio.h>
#define SIZE 10
struct student
{
	char no[10]; 	//ѧ��
	int score;		//�ɼ�
}; 

/////////////////////////////////////////////////////////////////////////
// Function:    int fun( struct student *stu1, struct student *stu2 )
// Description: ���ҳɼ�����ͬѧ����
// Input:        struct student *stu1��ָ��ԭʼѧ���ṹ����Ϣ��ָ��
//               struct student *stu2��ָ��ɼ����ѧ���ṹ����Ϣ��ָ��
// Output:       int n��               �ɼ�����ͬѧ����
///////////////////////////////////////////////////////////////////////// 
int fun( struct student *stu1, struct student *stu2 )
{
	int i, n, max;

	max = stu1[0].score;//�ٶ���λͬѧ�ĳɼ����
	for( i = 1; i < SIZE; i ++ )//�������ɼ�
		if( max < stu1[i].score )
			max = stu1[i].score;

	for( n = i = 0; i < SIZE; i ++ )//�������ɼ�����
		if( max == stu1[i].score )
			stu2[ n ++ ] = stu1[i];//�ҵ���ͬѧ���ݴ洢��stu2��

	return n;
}

void main( void )
{
	int i, n;

	struct student stu2[SIZE], stu1[SIZE]={{"P2203", 98}, {"P2201", 83},
             {"P2204", 65}, {"P2202", 87}, {"P2209", 77}, {"P2205", 98},
             {"P2207", 82}, {"P2206", 98}, {"P2208", 52}, {"P2210", 86}};


	n = fun( stu1, stu2 );

	puts( "ѧ�� �ɼ�" );
	for( i = 0; i < n; i ++ )
		printf("%s %d\n", stu2[i].no, stu2[i].score);
}

