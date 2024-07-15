// Program: EG0510.c 					    
// Description: 利用字符指针复制字符串
#include <stdio.h> 
void main( void )               	
{
	char *Str1="I am a teacher", *from=Str1;
	char *Str2="You are a student", *to=Str2;
	
    printf("Str1=%s  Str2=%s\n", Str1, Str2);
	for( ; *from != '\0'; from ++, to ++ )
		*to = *from;
	*to = '\0';
	
	printf("Str1=%s  Str2=%s\n",Str1,Str2);
}
