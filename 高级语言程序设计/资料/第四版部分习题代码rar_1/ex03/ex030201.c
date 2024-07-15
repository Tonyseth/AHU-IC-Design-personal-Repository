#include <stdio.h>
void main (void)
{
	int num, res;

	printf("Enter an integer:");
	scanf("%d", &num);

	res = (num % 5 == 0) + (num % 6 == 0);

	printf("Is %d divisible by 5 and 6? %s\n", 
		num, ( res == 2 )?"true":"false"); 
	printf("Is %d divisible by 5 or  6? %s\n",
		num, ( res >= 1 )?"true":"false");
	printf("Is %d divisible by 5 or 6, but not both? %s\n",
		num, ( res == 1 )?"true":"false");
}
