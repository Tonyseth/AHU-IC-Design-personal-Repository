#include <stdio.h>
#include <math.h>
#define Size 8
void main(void)
{
	short i;
	double array[Size]={2.6, 3.1, 4.7, 5.4, 6.0, 6.7, 9.4, 16.8 };  
	double x;
	printf("�������ĸ�����x:");
	scanf("%lf", &x);
	for(i=0; i<Size; i++)
		if(fabs(x-array[i])<1.0e-6)                                             
		{	 
			printf("�ҵ���������ڵ�%d��λ��\n", i+1);
			break;
		}
	if(i==Size)  
		printf("û�������\n");
}
