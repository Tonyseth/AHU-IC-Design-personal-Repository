// Program: EG0303.C 
// Description: 输入一元二次方程的三个系数a、b、c,要求计算并打印出方程的两个实数根 
#include <stdio.h>
#include <math.h>

void main (void)
{
	double a, b, c, deta, deta2, root1, root2;

	printf ("Input a, b, c:");
	scanf ("%lf,%lf,%lf", &a, &b, &c);

	deta = b * b - 4 * a * c;
	deta2 = sqrt(deta);
	root1 = (- b + deta2) / 2 / a;
	root2 = (- b - deta2) / 2 / a;

	printf ("Root1= %5.2lf Root2=%5.2lf\n", root1, root2);
}
