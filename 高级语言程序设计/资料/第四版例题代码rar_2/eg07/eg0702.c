// Program: EG0702.C 
// Description: 结构体变量数据传递示范
#include <stdio.h>
#include <string.h>
struct date
{
	unsigned int year;	//年
	unsigned int month;//月
	unsigned int day;	//日
}; 
struct student
{
	int no; 	//学号
	char name[16]; 	//姓名
	char sex; 	//性别
	struct date birthday; 	//出生日期
	float score[7];	//成绩数组
}; 
////////////////////////////////////////////////////////////
// Function:    struct student fun( struct student stu )
// Description: 修改传送过来的学生结构体数据
// Input:        struct student stu：学生结构体形参变量
// Output:       struct student stu：修改过的学生结构体数据
////////////////////////////////////////////////////////////  
struct student fun( struct student stu )
{
	int i;

	stu.no = 12206;
	strcpy( stu.name, "李四" );
	stu.birthday. year = 2008;
	stu.birthday.day = 22;
	for( i = 0; i < 7; i ++ )
		stu.score[i]++;

	return stu;
}

void main( void )
{
	int i;

	struct student stu1={12201, "张三", 'M', 2010, 5, 1,
		98, 87, 95, 65, 77, 83, 92}, stu2;

	stu2 = fun( stu1 );

	puts( "学号 姓名 性别 出生日期 成绩1 成绩2 成绩3 成绩4 成绩5 成绩6 成绩7" );
	printf("%d %s %s %d-%d-%d", stu2.no, stu2.name, stu2.sex=='F'?"女":
		"男", stu2.birthday.year, stu2.birthday.month, stu2.birthday.day);
	for( i = 0; i < 7; i ++ )
	{
		printf("%6.1f", stu2.score[i]);
	}
	printf("\n");
}


