// Program: EG0317.c
// Description: ����������������Ȼ�������Լ������С������
#include <stdio.h>
void main( void )
{
	int num1, num2, gcd, lcm, tmp;

	printf("Input num1,num2:");
	scanf("%d,%d", &num1, &num2);

	if( num1 > num2 )
		tmp = num1, num1 = num2, num2 = tmp;
	for( lcm = num2; lcm % num1 != 0; )
		lcm += num2;
	gcd = num1 * num2 / lcm;
	
	//for( ; gcd = num2 % num1; )
	//	num2 = num1,   num1 = gcd;
	//gcd = num1; 
    //lcm = num1 * num2 / gcd; 
	printf("gcd=%d  lcm=%d\n", gcd, lcm);
}
