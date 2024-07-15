// Program: EG0306.C
// Description: y=sign(x)? 
#include <stdio.h>

void main (void)
{ 
    double x;
    int sign;
	
    printf ("Input x:");
    scanf ("%lf", &x);

    if (x >= 0)
		if (x > 0)
			sign = 1;
		else
			sign = 0;
	else
		sign = -1;
		
	printf ("sign(%lf)=%d\n", x, sign);
}
