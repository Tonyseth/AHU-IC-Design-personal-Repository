#include <stdio.h>
int psum( int n )
{
	int i;
	for(i=n-1; i>0; i--)
		n+=i;
	return n;
}
void main( void )
{
	int n;
	for(n=1; n<20; n++)
	{
		printf("%2d--%3d\t", n, psum(n) );
		if(n%3==0) 
			printf("\n");
	}
}