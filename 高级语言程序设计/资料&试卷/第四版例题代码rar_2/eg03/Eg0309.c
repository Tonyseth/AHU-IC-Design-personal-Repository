// Program: EG0309.C
// Description: 从键盘输入一个百分制成绩,计算并输出五级记分制等级
#include <stdio.h>
void main( void )
{
	int score;

	printf("请输入一个百分制成绩:");
	scanf("%d", &score );

	switch( score / 10 )
     /*float score;
     printf("请输入一个百分制成绩:");
     scanf("%f", &score );
     switch( (int)score / 10 )*/
	{
	case 10:
	case 9:
		printf("A\n");
		break;
	case 8:
		printf("B\n");
		break;
	case 7:
		printf("C\n");
		break;
	case 6:
		printf("D\n");
		break;
	case 5:
	case 4:
	case 3:
	case 2:
	case 1:
	case 0:
		printf("E\n");
		break;
	default:
		printf("输入的成绩错误！\n");
	}
}
