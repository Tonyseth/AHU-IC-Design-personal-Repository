#include <stdio.h>
#include <string.h>
void count(char *str, int *iCh, int *iNum, int *iSpc)
{
	while(*str!='\0')
	{
		if(*str>='a' && *str<'z' || *str>'A' && *str<'Z')
			(*iCh)++;
		if(*str>'0' && *str<'9')
			(*iNum)++;
		if(*str==' ')
			(*iSpc)++;
		str++;
	}
}
void main( void )
{
	int i=0, j=0, k=0;
	char str[80];
	puts("Input a string:");
	gets(str);
	count(str, &i, &j, &k);
	printf("letter\tdigit\tspace\n%d\t%d\t%d\n", i, j, k);
}