/* Program: EG0105.c */
/* Description: �Ƚ��������������, ��ӡ�����. */
#include <stdio.h>	// ������׼I/O�⺯����˵��
int big( int num1, int num2 )	// �Ӻ���˵��
{
    int max;					// �ֲ�����˵��

    max=num1; 
    if(num2>max)				// �����
        max=num2;

    return max;					// ���ؽ��
}
void main( void )				// ������˵��
{
    int first, second, third, max;	// �ֲ�����˵��

    printf("��������������:");		// ��ʾ������ʾ���� 
    scanf("%d,%d,%d", &first, &second, &third);	// ��������

    max = big( first, second );		// ��first��second�еĴ���
    max = big( third , max );		// ��third��max�еĴ���

    printf("%d��%d��%d�е��������%d \n",
             first, second, third, max);		// ������ 
}
