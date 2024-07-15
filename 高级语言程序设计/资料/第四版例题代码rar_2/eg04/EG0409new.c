#include<stdio.h>
#include<math.h>
void main ( void )
{
	double x1, x0, a;

	printf("请输入想要求平方根的数：");
	scanf("%1f",&a);
	x0= a/2;
	x1= (x0 + a/x0)/2;
	while(fabs(x1-x0 )>= 1e-6)
	{
		x0 = x1;
		x1 = (x0 + a/x0)/2;
	}
	printf("the square root is%5.2f\n",x1);
}
