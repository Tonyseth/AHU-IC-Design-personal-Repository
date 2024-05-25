// Program: EG0319.c
// Description:  Print a calander.
#include <stdio.h>
void main( void )
{
	int month=0, week, maxday, day;

	printf("请输入月份:");
	scanf("%d", &month);
	printf("本月1号是周几(1-7)?");
	scanf("%d", &week);
	printf("本月一共有多少天:");
	scanf("%d", &maxday);

	printf("\n━━━━━━━━━  %2d 月  ━━━━━━━━━\n", month);
	printf("\n    日    一    二    三    四    五    六\n");
	++ week;
	if( week == 8 )
		day = week = 1;
	else
		day = week;
	while( day -- > 1 )
		printf("      ");
	day = 1;
	while( day <= maxday )
	{
		printf("%6d", day++);
		if( ++week == 8 )
		{
			printf("\n");
			week = 1;
		}
	}
	printf("\n");
}
