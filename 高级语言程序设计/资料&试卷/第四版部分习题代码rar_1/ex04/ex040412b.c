//ex040412b.c
#include<stdio.h>
void main ( void )
{
	char str[30],ch[256]={0};
	int i, j, k, n;
	
	gets(str);
	
    n=0; 
	while(str[n])
		n++;
	for(i=j=0; str[i]; i++)
	{
		for(k=i+1; k<n; k++)
			if(str[k]==str[i])
				break;
				
			if(k==n)
				str[j++]=str[i];
			
	}
	
	str[j]=0;
	
	printf("%s\n", str); 
}
