// Program: EG0704.C 
// Description: 模拟工资管理
#include <stdio.h>
#define N 5
typedef struct person
{
	int no; 	//编号
	char name[16]; 	//姓名
	float wage1; 	//基本工资
	float wage2; 	//岗位工资
	float wage; 	//总工资
}  PERSON;
void main( void )
{
	PERSON per[5], *ptr;	//定义结构体数组per、指针变量ptr
	float max;

	printf("请输入职工编号 姓名 基本工资,职务工资\n");
	for( ptr = per; ptr < per + N; ptr ++ )	//用per+N来控制循环次数
	{
		scanf("%d", &ptr->no);	//输入当前职工的编号
		scanf("%s", ptr->name);	//输入当前职工的姓名
		//输入当前职工的基本工资和职务工资
		scanf("%f,%f", &ptr->wage1, &ptr->wage2); 
		ptr->wage = ptr->wage1 + ptr->wage2;	//计算总工资
	}

	ptr = per;
	max = ptr->wage;	//假定首位职工的总工资最大
	for( ptr = per + 1; ptr < per + N; ptr ++ )
		if( max < ptr->wage)
			max = ptr->wage;

	printf("最大总工资=%4.0f\n", max);
}


