// Program: EG0319.c
// Description:  Print a calander.
#include <stdio.h>
void main( void )
{
	int month=0, week, maxday, day;

	printf("�������·�:");
	scanf("%d", &month);
	printf("����1�����ܼ�(1-7)?");
	scanf("%d", &week);
	printf("����һ���ж�����:");
	scanf("%d", &maxday);

	printf("\n������������������  %2d ��  ������������������\n", month);
	printf("\n    ��    һ    ��    ��    ��    ��    ��\n");
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
