// Program: EG0705.C 
// Description: 查找成绩最大的同学信息
#include <stdio.h>
#define SIZE 10
struct student
{
	char no[10]; 	//学号
	int score;		//成绩
}; 

/////////////////////////////////////////////////////////////////////////
// Function:    int fun( struct student *stu1, struct student *stu2 )
// Description: 查找成绩最大的同学人数
// Input:        struct student *stu1：指向原始学生结构体信息的指针
//               struct student *stu2：指向成绩最大学生结构体信息的指针
// Output:       int n：               成绩最大的同学人数
///////////////////////////////////////////////////////////////////////// 
int fun( struct student *stu1, struct student *stu2 )
{
	int i, n, max;

	max = stu1[0].score;//假定首位同学的成绩最大
	for( i = 1; i < SIZE; i ++ )//查找最大成绩
		if( max < stu1[i].score )
			max = stu1[i].score;

	for( n = i = 0; i < SIZE; i ++ )//查找最大成绩人数
		if( max == stu1[i].score )
			stu2[ n ++ ] = stu1[i];//找到的同学数据存储到stu2中

	return n;
}

void main( void )
{
	int i, n;

	struct student stu2[SIZE], stu1[SIZE]={{"P2203", 98}, {"P2201", 83},
             {"P2204", 65}, {"P2202", 87}, {"P2209", 77}, {"P2205", 98},
             {"P2207", 82}, {"P2206", 98}, {"P2208", 52}, {"P2210", 86}};


	n = fun( stu1, stu2 );

	puts( "学号 成绩" );
	for( i = 0; i < n; i ++ )
		printf("%s %d\n", stu2[i].no, stu2[i].score);
}

