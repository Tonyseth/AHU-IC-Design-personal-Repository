// Program: EG0413a.C 
// Description: ����strcmp������ʵ�ֶ����������ַ����ıȽϡ�
#include <stdio.h>
void main( void )
{
    char string1[20], string2[20];
    short i; 
 
    printf("���������ַ���:\n");
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
