#include <stdio.h>
void main (void)
{
	int i = 1;
    /***error***/
	int s, t;

	while(i<=7)
	{  
		t = t + 5;
		s = s + t;
		t = t * 10;
		/***error***/
	}

	printf ("%d\n", s);             
}
