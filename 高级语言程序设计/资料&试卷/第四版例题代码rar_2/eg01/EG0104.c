/* Program: EG0104.c */
/* Description: �Ƚ�������ĸ�������, ��ӡ��С�� */
#include <stdio.h>                 				// ������׼I/O�⺯����˵�� 

void main (void)                    			// ������˵�� 
{
	float first, second, third, fourth, min; 	// �ֲ�����˵�� 

    printf ("�������ĸ�������:");            	// ��ʾ������ʾ���� 
    scanf ("%f,%f,%f,%f", &first, &second, &third, &fourth); // ��������

    min = first;
    if (second < min)                 			//��first��second�е�С��
		min = second;
    if (third < min)                  			//��third��min�е�С��
		min = third;
    if (fourth < min)               			//��fourth��min�е�С��
		min = fourth;

    printf ("%f��%f��%f��%f�е���С����%f\n",
		first, second, third, fourth, min);		// ������
}
