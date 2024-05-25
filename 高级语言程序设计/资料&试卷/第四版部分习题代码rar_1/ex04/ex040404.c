#include <stdio.h> 
void main(void) 
{
	unsigned short num[100];
	unsigned short i, j, k=0;
	unsigned short one, ten, hun;

	for(i=100; i<=999; i++)
	{
		j=10;
		while(j*j<=i)
		{
			one=i%10;
			ten=(i/10)%10;
			hun=i/100;
			if(i==j*j)
				if(one==ten || one==hun || ten==hun) 
					num[k++]=i;
			j++;
		}
	}
	
	printf("有%d个这样的数：", k);
	for(i=0; i<k; i++)
		printf("%4d", num[i]);
	printf("\n");

}
