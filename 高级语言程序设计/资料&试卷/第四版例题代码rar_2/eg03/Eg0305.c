// Program: EG0305.C 
// Description: �Ӽ�������һ�����, Ҫ���жϳ����Ƿ���ƽ�� 
#include <stdio.h>

void main (void)
{
	int year; 

	printf ("������һ�����:");
	scanf ("%d", &year);

	if (((year % 100 != 0) && (year % 4 != 0)) ||
		((year % 100 == 0) && (year % 400 != 0)))
		printf ("%d ��ƽ�ꡣ\n", year);
	else
		printf ("%d ����ƽ�ꡣ\n", year);
}
