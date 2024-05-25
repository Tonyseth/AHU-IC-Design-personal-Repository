#include <stdio.h>
/***********ERROR***********/
//void swap(short x, short y)
void swap(short *x, short *y)
{
	short tmp;
	/***ERROR***/
//	tmp=x;
	tmp=*x;
	/***ERROR***/
//	x=y;
	*x=*y;
	/***ERROR***/
//	y=tmp;
	*y=tmp;
}
void main(void)
{
	short x, y;
	printf("Input two short num :");
	scanf("%d%d", &x, &y );
	if(x<y)
		/***ERROR***/
//		swap(x, y);
		swap(&x, &y);
	printf("After swaped, x=%d, y=%d\n", x, y );
}