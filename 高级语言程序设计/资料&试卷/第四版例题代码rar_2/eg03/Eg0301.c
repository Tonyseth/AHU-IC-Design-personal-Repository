// Program: EG0301.C 
// Description: ����Բ�İ뾶, ���ӦԲ���ܳ������ 
#include <stdio.h>          					// ������׼I/O�⺯����˵�� 
#define PAI 3.141593     						// ������ų���PAI
void main( void )                   			// ������˵�� 
{
	double radius, perimeter, area ;   			// �ֲ�����˵�� 

	printf("������Բ�İ뾶:");    				// ��ʾ������ʾ���� 
	scanf("%lf", &radius);          			// ����뾶  

	perimeter = 2 * PAI * radius;   			// ��Բ�ܳ� 
	area = PAI * radius * radius;   			// ��Բ��� 

	printf("�ܳ���%5.2lf, �����%5.2lf\n",
		perimeter, area);   					// ������ 
}

