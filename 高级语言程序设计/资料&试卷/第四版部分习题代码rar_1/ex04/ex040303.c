#include<stdio.h>
/*******ERROR*******/
void main(void)
{
	char StrName[5][10], Strtmp[10];
	int i, j, tmp;

	printf("input country's name:\n");
	for( i = 0; i < 5; i ++ )
		gets(StrName[i]);

	for( i = 0; i < 5; i ++ )
	{
		for( tmp = i, j = i + 1; j < 5; j ++ )
			/************ERROR************/
			if( StrName[j] < StrName[tmp] )
				tmp = j;
		if( tmp != i )
		{
			/*********ERROR*********/
			Strtmp = StrName[tmp];
			StrName[tmp] = StrName[i];
			StrName[i] = Strtmp;
		}
		puts( StrName[i] );
	}
}

