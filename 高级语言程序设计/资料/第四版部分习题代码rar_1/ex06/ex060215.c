#include <stdio.h>
int  pow( int x, int y )
{
	int j;

	for ( j=1 ; y>0 ; y-- )
          j = j * x;

     return j;
}
void main(void)
{
	int x=4;

	printf("%d\n", pow(x, 3));
} 