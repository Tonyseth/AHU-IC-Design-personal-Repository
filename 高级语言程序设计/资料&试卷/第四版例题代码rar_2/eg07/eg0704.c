// Program: EG0704.C 
// Description: ģ�⹤�ʹ���
#include <stdio.h>
#define N 5
typedef struct person
{
	int no; 	//���
	char name[16]; 	//����
	float wage1; 	//��������
	float wage2; 	//��λ����
	float wage; 	//�ܹ���
}  PERSON;
void main( void )
{
	PERSON per[5], *ptr;	//����ṹ������per��ָ�����ptr
	float max;

	printf("������ְ����� ���� ��������,ְ����\n");
	for( ptr = per; ptr < per + N; ptr ++ )	//��per+N������ѭ������
	{
		scanf("%d", &ptr->no);	//���뵱ǰְ���ı��
		scanf("%s", ptr->name);	//���뵱ǰְ��������
		//���뵱ǰְ���Ļ������ʺ�ְ����
		scanf("%f,%f", &ptr->wage1, &ptr->wage2); 
		ptr->wage = ptr->wage1 + ptr->wage2;	//�����ܹ���
	}

	ptr = per;
	max = ptr->wage;	//�ٶ���λְ�����ܹ������
	for( ptr = per + 1; ptr < per + N; ptr ++ )
		if( max < ptr->wage)
			max = ptr->wage;

	printf("����ܹ���=%4.0f\n", max);
}


