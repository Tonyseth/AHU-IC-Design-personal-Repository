#include <stdio.h> 
void  main (void)
{
	float a, b, c, t;

	printf("Input a,b,c:");
	scanf("%f,%f,%f", &a, &b, &c);

	if( a > b )
		/***ERROR***/
		t = a; a = b; b = t;
	if( a > c )
		/***ERROR***/
		t = a; a = c; c = t;
	if( b > c )
		/***ERROR***/
		t = b; b = c; c = t;

	printf("%f,%f,%f\n", a, b, c);
}
