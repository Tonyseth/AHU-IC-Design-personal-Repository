#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAXLENGTH 20
int mystrcmp(char *q1, char *q2)
{
	int n=0;
	while(q1[n]==q2[n])
		n++;
	return(abs(q1[n]-q2[n]));
}
void main( void )
{
	char str1[MAXLENGTH];
	char str2[MAXLENGTH];
	printf("Input two srtings:\n");
	scanf("%s", str1);
	scanf("%s", str2);
	printf("|str1-str2|=%d\n", mystrcmp(str1, str2));
}