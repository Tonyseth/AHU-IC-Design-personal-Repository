#include <stdio.h>
void max_min(double *num, int n, double *max, double *min)
{
	int i;
	for (i=1;i<n;i++)
	{
		if (num[i]>*max)
			*max=num[i];
		if (num[i]<*min)
			*min=num[i];
	}
}
void main( void )
{
	int i;
	double Num[10], dmax, dmin;
	printf("Input 10 num:\n");
	for (i=0; i<10; i++)
		scanf("%lf", Num+i);
	dmax=dmin=Num[0];
	max_min(Num, 10, &dmax, &dmin);
	printf("Output 10 num:\n");
	for (i=0; i<10; i++)
		printf("%3.1lf ", Num[i]);
	printf("\nmax num :%lf  min num :%lf\n", dmax, dmin);
}