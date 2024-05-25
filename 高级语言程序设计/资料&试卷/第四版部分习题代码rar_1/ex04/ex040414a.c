//ex040414.c
#include<stdio.h>
#define SIZE 10
void main()
{
	int Num[SIZE];
	int  i, j, count=0;

	for(i=0; i<SIZE; i++ )
		scanf("%d", &Num[i]);

	for(i=0; i<SIZE; i++ )
	{
		for(j=i+1; j<SIZE; j++)
			if( Num[j]==Num[i] ) 
				break;
		if( j==SIZE )
			count++;
	}

	printf("%d\n",count);
}
