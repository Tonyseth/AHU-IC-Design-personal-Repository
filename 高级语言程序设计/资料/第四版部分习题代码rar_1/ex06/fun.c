#include <stdio.h>
void fun( int n )
	{
		int i=2;
		printf("%d=", n);
		while(i<=n)
			if(n%i==0)
			{
				printf("%d*", i);
				n=n/i;
			}
			else
				i++;
		printf("\b \n");
}