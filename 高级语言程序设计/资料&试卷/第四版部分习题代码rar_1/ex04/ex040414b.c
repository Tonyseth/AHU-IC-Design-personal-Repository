#include<stdio.h>
#define SIZE 10
void main()
{
	int Num[SIZE];
	int  i, j, count=10;

	for(i=0; i<SIZE; i++ )
		scanf("%d", &Num[i]);

	for(i=0; i<SIZE; i++ )
	{
		for(j=i+1; j<SIZE; j++)
			if( Num[j]==Num[i] ) 
			{
				count--;
				break;
			}
			
	}

	printf("%d\n",count);
}
