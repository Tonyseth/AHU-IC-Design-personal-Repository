// Program: EG0512.c 
// Description: 使用字符指针删除输入字符串的前导星号。
#include <stdio.h> 
#include <string.h>
void main( void )               	
{
	char Str[80], *ps1, *ps2;

	gets( Str );

	ps1 = ps2 = Str; 
	// 寻找第一个非星号字符
	while( *ps1 == '*' )
		ps1 ++;
	// 复制剩余字符
	while( *ps1 != '\0' )
	{
		*ps2 = *ps1;
		++ ps1;
		++ ps2;
	}
	// 新串末尾添加字符串结束符
	*ps2 = '\0';

	puts( Str );
}
