#include <stdio.h>
//�궨��
#define SQU(x) (x)*(x)
void main( void )
{
	float a, b;
	printf("input a, b:");
	scanf("%f,%f", &a, &b);
	printf("SQU(a+b)=%f\n", SQU(a+b)); //���ú�
	printf("SQU(a-b)=%f\n", SQU(a-b)); //���ú�
}