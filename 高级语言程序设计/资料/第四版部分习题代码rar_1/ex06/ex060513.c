#include <stdio.h>
short judge(int num)
{
	int s=1, i;
	for(i=2; i<num; i++)
		if(num%i==0)
			s=s+i;
	if(s==num)
		return s;
	else
		return 0;
}
void main(void)
{
	short n;
	printf("1000 以内的完数:");
	for(n=2; n<1000; n++)
		if (judge(n))
			printf("%4d", judge(n));
	printf("\n");
}