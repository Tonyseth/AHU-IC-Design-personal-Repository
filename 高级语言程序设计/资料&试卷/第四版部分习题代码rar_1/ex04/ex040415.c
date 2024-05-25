//ex040415.c
#include<stdio.h>
void main ( void )
{
	char str[30];
	int i, j;

	gets(str);
    i=0; j=0; 
	while(str[i]!=0)
	{
		if(str[i]<'0'||str[i]>'9')
		{
		  str[j]=str[i];
		  j++;
		}
	    i++;
	}
    str[j]=0;
	printf("%s\n", str); 
}
