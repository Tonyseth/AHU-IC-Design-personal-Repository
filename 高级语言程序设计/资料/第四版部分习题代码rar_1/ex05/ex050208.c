#include <stdio.h>
void main( void )
{
	int a[2][3]={{1, 2, 3}, {4, 5, 6}}, m, *p;

	p = &a[0][0];
	m = (*p) * (*(p+2)) * (*(p+4));

	printf("%d", m); 
}
