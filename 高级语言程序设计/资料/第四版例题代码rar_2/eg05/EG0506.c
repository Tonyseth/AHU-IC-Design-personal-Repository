// Program: EG0506.c 
// Description: 利用指针相减求字符串长度
#include <stdio.h> 
void main( void )
{
	char Str[20], *Ptr;

	printf("请输入一字符串:");
	gets( Str );

	Ptr = Str;
	while( * Ptr != '\0' )
		Ptr ++; 

	printf("字符串长度为%d\n", Ptr - Str);
}
