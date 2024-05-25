#include <stdio.h>
void main(void)
{
	int a[3][3]={1, 2, 3, 4, 5, 6, 7, 8, 9}, i;    

	for( i = 0; i < 3; i ++ )
		printf("%d,", a[i][2 - i]);
}

