// Program: EG0513.c 
// Description: 使用字符指针删除输入字符串的中部星号。
#include <stdio.h> 
void main( void )               	
{
	char Str[80], *ps1, *ps2, *ps3;

	gets( Str );

	ps1 = Str; 
	// 寻找第一个非星号字符
	while( *ps1 == '*' )
		ps1 ++;
	// 寻找字符串结束符
	ps2 = ps3 = ps1; 
	while( *ps3 != '\0' )
		ps3 ++;
	// 寻找尾部第一个星号字符
	ps3--;
	while( *ps3 == '*' )
		ps3 --;
	ps3++;

	// 复制中部非星号字符
	while( ps1 < ps3 )
	{
		if( *ps1 != '*' )
		{
			*ps2 = *ps1;
			++ ps2;
		}
		++ ps1;
	}
	// 新串末尾复制尾部星号及字符串结束符
	while( *ps2 = *ps3 )
		++ ps2, ++ ps3;

	puts( Str );
}
