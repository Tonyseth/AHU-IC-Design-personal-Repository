#include <stdio.h>
int *f( int *x, int *y )
{
	if( *x < *y )
		return x;
	else
		return y;
}
void main(void)
{
	int a=7, b=8, *p, *q, *r;

	p = &a;
	q = &b;
	r = f( p, q );

	printf("%d,%d,%d\n", *p, *q, *r);
} 