// Program: EG0308.C
// Description: �Ӽ�������һ���������㣬���㲢������
#include <stdio.h>
void main( void )
{
    float num1, num2;
    char op;

    printf("������һ������������ʽ(eg:1.5/2.5):");
    scanf("%f%c%f", &num1, &op, &num2 );

    switch( op )
    {
		case '+':
			printf("%f + %f = %f\n", num1, num2, num1 + num2);
			break;
		case '-':
			printf("%f - %f = %f\n", num1, num2, num1 - num2);
			break;
		case '*':
			printf("%f * %f = %f\n", num1, num2, num1 * num2);
			break;
		case '/':
			if(num2)
				printf("%f / %f = %f\n", num1, num2, num1 / num2);
			else
				printf("��������Ϊ0\n");
			break;
		default:
			printf("������������\n");
    }
}
