#include<stdio.h>
void main (void)
{
	int a, i = 1, min;

    while( i <= 5 )
    {
		printf ("\n请输入第%d个数据：", i);		
		scanf ("%d", &a);
		/***error***/
		if( min >= a )  
			min = a;
		i = i + 1;
	}

	printf ("min=%d\n", min);					
}
