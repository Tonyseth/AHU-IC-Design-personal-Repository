// Program: EG0701.C 
// Description: 结构体变量应用示范:初始化stu1,赋值给stu2打印输出
#include <stdio.h>
void main( void )
{
     int i;
     struct date
     {
          unsigned int year;	//年
          unsigned int month;	//月
          unsigned int day;		//日
     }; 
     struct student
     {
          int no; 	//学号
          char name[16]; 	//姓名
          char sex; 	//性别
          struct date birthday; 	//出生日期
          float score[7];	//成绩数组
     } stu2; 
     struct student stu1={11301, "Merry", 'F', 2010, 5, 1,
                              98, 87, 95, 65, 77, 83, 92};

     stu2 = stu1;
     puts( "学号 姓名 性别 出生日期 成绩1 成绩2 成绩3 成绩4 成绩5 成绩6 成绩7" );
     printf("%d %s %s %d-%d-%d", stu2.no, stu2.name, stu2.sex=='F'?"女":
           "男", stu2.birthday.year, stu2.birthday.month, stu2.birthday.day);
	     for( i = 0; i < 7; i ++ )
	     {
	          printf("%6.1f", stu2.score[i]);
	     }
	printf( "\n" );
}

