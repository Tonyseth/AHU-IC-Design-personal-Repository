#include <stdio.h>
/*****ERROR*****/
//max(int x, y, z)
int max(int x, int y) 
{
	/***ERROR***/
//	z=x>y?x,y;
	int z;
	z=x>y?x:y;
	return(z);
}
void main(void)
{
	printf("Max(5,6)=%d\n", max(5, 6));
}