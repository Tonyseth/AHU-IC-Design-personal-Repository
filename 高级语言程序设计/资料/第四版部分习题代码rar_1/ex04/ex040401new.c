#include <stdio.h>
#include <math.h>
#define Size 8
void main(void)
{
	short i;
	double array[Size]={2.6, 3.1, 4.7, 5.4, 6.0, 6.7, 9.4, 16.8 };  
	double x;
	printf("输入待查的浮点数x:");
	scanf("%lf", &x);
	for(i=0; i<Size; i++)
		if(fabs(x-array[i])<1.0e-6)                                             
		{	 
			printf("找到这个数，在第%d个位置\n", i+1);
			break;
		}
	if(i==Size)  
		printf("没有这个数\n");
}
