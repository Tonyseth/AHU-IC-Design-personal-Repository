// Program: EG0308.C
// Description: 从键盘输入一个四则运算，计算并输出结果
#include <stdio.h>
void main( void )
{
    float num1, num2;
    char op;

    printf("请输入一个四则运算表达式(eg:1.5/2.5):");
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
				printf("除数不能为0\n");
			break;
		default:
			printf("错误的运算符！\n");
    }
}
