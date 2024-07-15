#include <stdio.h>
#include <string.h>
#define MAXLENGTH 20
void sort( char **p2, int n )
{
	char *tmp;
	int i, j;
	for( i=0; i<n-1; i++ )
		for( j=0; j<n-i-1; j++ )
			if(strcmp(p2[j], p2[j+1])>0)
				tmp=p2[j], p2[j]=p2[j+1], p2[j+1]=tmp;
}
void main( void )
{
	int k;
	char **p2, *p1[10], s[10][MAXLENGTH];
	for(k=0; k<10; k++)
		p1[k] = s[k];
	printf("Enter 10 strings\n");
	for(k=0; k<10; k++)
		scanf("%s", p1[k]);
	p2=p1;
	sort(p2, 10);
	printf("The sorted srtings are:\n");
	for(k=0; k<10; k++)
		printf("%s ", p1[k]);
	printf("\n");
}