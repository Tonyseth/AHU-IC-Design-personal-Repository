/* Program: EG0103.c */
/* Description: Comparing first and second, see which is the bigger. */
#include <stdio.h>                        // ������׼I/O�⺯����˵�� 
void main( void )                         // ������˵�� 
{
	int first, second, max;               // �ֲ�����˵�� 

	printf("��������������:");            // ��ʾ������ʾ���� 
	scanf("%d,%d", &first, &second);      // �Ӽ����������ݴ������ 

	max = first;                          // ��first��Ϊ��ֵ����max
	if( second > max )                    // �Ƚ�max��second
		max = second;                     // ���ϴ��secondֵ����max

	printf("��һ������%d\n", first);      // ������ 
	printf("�ڶ�������%d\n", second);
	printf("������%d\n", max);
}

