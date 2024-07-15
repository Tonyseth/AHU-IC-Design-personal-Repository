//ex040412.c
#include<stdio.h>
void main ( void )
{
	char str[30];
	int i, j, k, n;

	gets(str);

    n=0; 
	while(str[n])
		n++;
	for(i=0; i<n-1; i++)
	{
		for(j=k=i+1; k<n; k++)
			if(str[k]!=str[i])
				str[j++]=str[k];
		while(j<n)
			str[j++]=0;
		n--;
	}

	printf("%s\n", str); 
}
