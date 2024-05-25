#include <stdio.h>
#include <string.h>
int judge(char str[])
{
	int i, j;
	i=0; j=strlen(str)-1;
	while(i<j)
	{
		if(str[i]!=str[j])
			break;
		i++, j--;
	}
	if(i>=j) 
		return(1);
	else
		return(0);
}

void main(void)
{ 
	char Str[100];
	scanf("%s", Str);
	if(judge(Str)) 
		printf("Yes\n");
	else
		printf("No\n");
}