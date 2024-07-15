//ex040413.c
#include <stdio.h>
void main (void)
{ 
	int i, j, a[11][11]={0, 1};
	
    for(i=1; i<=10; i++)
    { 
//		for(j=1;j<2*(10-i);j++)
//			printf("o");   
		for(j=1;j<=i;j++)
		{ 
			a[i][j]=a[i-1][j-1]+a[i-1][j];  
			printf("%4d",a[i][j]);   
		}
		printf("\n");
	}
}