// Program: EG0706.C 
// Description: 学生成绩管理菜单框架示范
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
	system( "cls" );		// 清屏  
	system( "color 3F" );	// 颜色设置：3 湖蓝色背景  F 亮白色前景 
	printf("\n---欢迎使用学生成绩管理系统---\n");
	printf("  1.成绩录入              \n");
	printf("  2.成绩查询              \n");
	printf("  0.退出系统              \n");
	printf("------------------------------\n");
	printf("请输入您的选择：");
}

int ChooseMenu( void )
{
	int choice;				//用户选择

	scanf("%d", &choice);
	
	return choice;
}
int input( struct student *stu )
{
	int i, n;

	printf("\n请输入要录入的学生人数n：");
	scanf("%d", &n);                  
	printf("请输入%d个学生的学号 姓名 成绩1 成绩2 成绩3\n", n);
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

	printf("\n请输入姓名或学号查询:");
	scanf("%s", str);

	for( i = 0; i < n; i ++ )
	{     
		if(!strcmp( str, stu[i].number )||!strcmp( str, stu[i].name ))
		{
			printf("查询到学号%s的%s同学:", stu[i].number, stu[i].name);
			printf("成绩1:%4d 2:%4d 3:%4d\n\n",
				stu[i].score1, stu[i].score2, stu[i].score3);
			return;
		}
	}
	printf("亲，没有这个人！\n");
}

void main()
{
	struct student stu[N];
	int n;					//学生人数

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
			printf("选错菜单了！\n");
		}

		system( "pause" );		// 暂停，按任意键继续
	}
}
