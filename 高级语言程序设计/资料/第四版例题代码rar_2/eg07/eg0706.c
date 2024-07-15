// Program: EG0706.C 
// Description: ѧ���ɼ�����˵����ʾ��
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define N 5
struct student
{
	char number[10];
	char name[16];
	int score1;
	int score2;
	int score3;
}; 

void ShowMenu( void )
{
	system( "cls" );		// ����  
	system( "color 3F" );	// ��ɫ���ã�3 ����ɫ����  F ����ɫǰ�� 
	printf("\n---��ӭʹ��ѧ���ɼ�����ϵͳ---\n");
	printf("  1.�ɼ�¼��              \n");
	printf("  2.�ɼ���ѯ              \n");
	printf("  0.�˳�ϵͳ              \n");
	printf("------------------------------\n");
	printf("����������ѡ��");
}

int ChooseMenu( void )
{
	int choice;				//�û�ѡ��

	scanf("%d", &choice);
	
	return choice;
}
int input( struct student *stu )
{
	int i, n;

	printf("\n������Ҫ¼���ѧ������n��");
	scanf("%d", &n);                  
	printf("������%d��ѧ����ѧ�� ���� �ɼ�1 �ɼ�2 �ɼ�3\n", n);
	for( i = 0; i < n; i ++ )
	{
		scanf("%s", stu[i].number);
		scanf("%s", stu[i].name );
		scanf("%d", &stu[i].score1);
		scanf("%d", &stu[i].score2);
		scanf("%d", &stu[i].score3);
	}

	return n;
}
void find(struct student stu[], int n)
{
	int i;
	char str[16];

	printf("\n������������ѧ�Ų�ѯ:");
	scanf("%s", str);

	for( i = 0; i < n; i ++ )
	{     
		if(!strcmp( str, stu[i].number )||!strcmp( str, stu[i].name ))
		{
			printf("��ѯ��ѧ��%s��%sͬѧ:", stu[i].number, stu[i].name);
			printf("�ɼ�1:%4d 2:%4d 3:%4d\n\n",
				stu[i].score1, stu[i].score2, stu[i].score3);
			return;
		}
	}
	printf("�ף�û������ˣ�\n");
}

void main()
{
	struct student stu[N];
	int n;					//ѧ������

	while( 1 ) 
	{ 
		ShowMenu();
		
		switch( ChooseMenu() )
		{
		case 1:
			n = input( stu );
			break;
		case 2:
			find( stu, n );
			break;                                                                
		case 0:
			exit(0);
			break;		
		default:
			printf("ѡ��˵��ˣ�\n");
		}

		system( "pause" );		// ��ͣ�������������
	}
}
