#include <stdio.h>
double sum( double x, int n )
{
	int i;
	/*****ERROR*****/
//	double a, b, s;
	double a=1.0, b=1.0, s=1.0;
	for(i=1; i<=n; i++)
	{
		a=a*x;
		b=b*i;
		s=s+a/b;
	}
	return s;
}
void main(void)
{
	double x=6;
	int n=3;
	printf("s(%6.2lf, %d)=%6.2lf\n", x, n, sum(x, n));
}