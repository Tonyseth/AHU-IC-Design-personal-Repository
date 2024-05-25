// Program: EG0322.c
#include <stdio.h>
void main(void)
{
	int i, num, count=0, sum=0;

	printf("Please input ten numbers:\n");
	for( i = 0; i < 10; i ++ )
	{
		scanf("%d", &num);
		if( num <= 0 )
			continue;
		count ++;
		sum += num;
	}

	printf("You have input %d positive integers \n", count);
	printf("The average value of these positive integers is %6.2f\n",
		(float) sum / count );
}