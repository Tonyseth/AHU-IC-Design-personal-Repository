// Program: EG0702.C 
// Description: �ṹ��������ݴ���ʾ��
#include <stdio.h>
#include <string.h>
struct date
{
	unsigned int year;	//��
	unsigned int month;//��
	unsigned int day;	//��
}; 
struct student
{
	int no; 	//ѧ��
	char name[16]; 	//����
	char sex; 	//�Ա�
	struct date birthday; 	//��������
	float score[7];	//�ɼ�����
}; 
////////////////////////////////////////////////////////////
// Function:    struct student fun( struct student stu )
// Description: �޸Ĵ��͹�����ѧ���ṹ������
// Input:        struct student stu��ѧ���ṹ���βα���
// Output:       struct student stu���޸Ĺ���ѧ���ṹ������
////////////////////////////////////////////////////////////  
struct student fun( struct student stu )
{
	int i;

	stu.no = 12206;
	strcpy( stu.name, "����" );
	stu.birthday. year = 2008;
	stu.birthday.day = 22;
	for( i = 0; i < 7; i ++ )
		stu.score[i]++;

	return stu;
}

void main( void )
{
	int i;

	struct student stu1={12201, "����", 'M', 2010, 5, 1,
		98, 87, 95, 65, 77, 83, 92}, stu2;

	stu2 = fun( stu1 );

	puts( "ѧ�� ���� �Ա� �������� �ɼ�1 �ɼ�2 �ɼ�3 �ɼ�4 �ɼ�5 �ɼ�6 �ɼ�7" );
	printf("%d %s %s %d-%d-%d", stu2.no, stu2.name, stu2.sex=='F'?"Ů":
		"��", stu2.birthday.year, stu2.birthday.month, stu2.birthday.day);
	for( i = 0; i < 7; i ++ )
	{
		printf("%6.1f", stu2.score[i]);
	}
	printf("\n");
}


