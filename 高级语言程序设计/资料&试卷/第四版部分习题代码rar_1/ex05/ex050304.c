#include <stdio.h>
#include <string.h>
void main( void )               	
{
	/*****************ERROR*****************/
	char Str1[]="teacher", Str2[]="student";
    char *tmp;

	/*****ERROR*****/
	if( Str1 < Str2 )	
		tmp = Str1, Str1 = Str2, Str2 = tmp;
	
	printf("str1=%s\nstr2=%s\n", Str1, Str2);
}

