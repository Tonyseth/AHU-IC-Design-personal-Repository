#include <stdio.h>
void main( void )
{
	int a,b;
	/*********ERROR*********/
	double area(int a, int b);
	scanf("%d,%d",&a,&b);
	/**************ERROR****************/
//	printf("the area is %d\n", area(a,b) );
	printf("the area is %lf\n", area(a,b) );
}
/***********ERROR***********/
//double area(double a; double b)
double area(int a, int b)
{
	return(3.14159*a*b/2);
}