#include <stdio.h>	// ������׼I/O�⺯��˵�� 
void main(void)	// ������˵�� 
{
    float first, second, third, max;	// �ֲ�����˵�� 
    printf("����������������:");	// ��ʾ������ʾ���� 
    scanf("%f%f%f", &first, &second, &third);	// ��������
    
    max = first;
    if( second > max )	//��first��second�еĴ���
		max = second;
    if( third > max )	//��third��max�еĴ���
		max = third;
    printf("%f��%f��%f�е��������%f\n", first, second, third, max);	// ������
}
