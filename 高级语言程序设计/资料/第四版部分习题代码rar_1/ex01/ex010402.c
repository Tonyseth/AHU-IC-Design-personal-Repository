#include <stdio.h>	// ������׼I/O�⺯��˵�� 
int small(int num1, int num2) 	// �Ӻ���˵��
{
	int min=num1; 	// �ֲ�����˵��
	if( min > num2 )	// ���С�� 
		min = num2;
	return min;	// ���ؽ�� 
}
void main(void)	// ������˵��
{ 
    int first, second, third, min;	// �ֲ�����˵�� 
    printf("��������������: ");	// ��ʾ������ʾ���� 
    scanf("%d%d%d", &first, &second, &third);	// �������� 
    min = small( first, second );	// ��first��second�еĽ�С��
    min = small( third, min );	// ��third��min�еĽ�С��
    printf("%d��%d��%d�е���С����%d\n",
        first, second, third, min);	// ������ 
}
