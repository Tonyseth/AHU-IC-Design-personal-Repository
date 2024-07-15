#include <stdio.h>
short regress(int num)
{
	int i, j, k, a[20], s;
	int num1, n=0;
	num1=num;
	while(num1!=0) //判断数字的位数
	{
		num1=num1/10;
		n++;
	}
	s=0;
	num1=num;
	for (i=n; i>0; i--)
	{
		k=1;
		for (j=1; j<i; j++)
			k=k*10;
		a[i]=num1/k;
		num1=num1-a[i]*k;
		k=a[i];
		for (j=1; j<n; j++)
			a[i]=a[i]*k;
		s=s+a[i];
	}
	if (s==num)
		return num;
	else
		return 0;
}
void main( void )
{
	short n, nok[100], i=0;
	for(n=100; n<1000; n++) //检测全部三位数
		if (regress(n)==n)
			nok[i++]=n;
	printf("3次幂回归数:");
	for (n=0; n<i; n++)
		printf("%4d", nok[n]);
    printf("\n");
}