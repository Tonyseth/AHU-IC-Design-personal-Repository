// Program: EG0413a.C 
// Description: 不用strcmp函数，实现对输入两个字符串的比较。
#include <stdio.h>
void main( void )
{
    char string1[20], string2[20];
    short i; 
 
    printf("输入两个字符串:\n");
    gets(string1);
    gets(string2);
 
    for (i = 0; string1[i] == string2[i]; i++) 
         if (string1[i] == '\0') 
               break; 

    if( string1[i] - string2[i] >0 )
		printf("%s>%s\n", string1, string2);
	else
		if( string1[i] - string2[i] ==0 )
			printf("%s==%s\n", string1, string2);
		else
			printf("%s<%s\n", string1, string2);
}
