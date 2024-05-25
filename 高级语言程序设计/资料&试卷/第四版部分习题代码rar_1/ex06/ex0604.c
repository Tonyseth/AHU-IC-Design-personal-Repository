#include<stdio.h>
#include<string.h>
void count(char *string,int *iCh,int *iNum,int *iSpc)
{   
	while(*string!='\0')
	{
		if(*string>='a' && *string<'z' || *string>'A' && *string<'Z')
			(*iCh)++;
		if(*string>'0' && *string<'9')
			(*iNum)++;
		if(*string==' ')
			(*iSpc)++;
		string++;
	}
}
void main( void )
{
	int i=0,j=0,k=0;
	char str[20];
	puts("Input some words:");
	gets(str);
	count(str,&i,&j,&k);
	printf("\n%d  %d  %d\n",i,j,k);
}
