#include <stdio.h>
//��������
float max(float m, float n)
{
	if (m>n)
		return m;
	else
		return n;
}
//�궨��
#define MAX(x, y) x>y?x:y
void main( void )
{
	float a, b, c;

	printf("input a, b, c:");//���ú�
	scanf("%f,%f,%f", &a, &b, &c);

	printf("MAX=%f\n", MAX(MAX(a, b), MAX(b, c)));//���ú�
	printf("max=%f\n", max(max(a, b), max(b, c)));//���ú���
}