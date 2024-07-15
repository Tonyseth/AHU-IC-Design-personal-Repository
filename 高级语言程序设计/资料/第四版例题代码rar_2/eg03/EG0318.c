// Program: EG03-18.c
// Description: 编程打印指定的星形图案
#include <stdio.h>
void main( void )
{ 
	char star='*', space=' ';               // 定义打印符号
	int i, j;                                  // 定义内、外循环控制变量
	int num1, num2;                           // 定义各控制变量

	for( i = 0; i < 7; i ++ )               // 行控制
	{
		if( i < 4 )
			num1 = 3 + i, num2 = 7 - i * 2;// i<4的规律
		else
			num1 = 9 - i, num2 = i * 2 - 5;// i>=4的规律
		for( j = 0; j < num1; j ++ )
			putchar(space);                 // 输出num1个空格
		for( j = 0; j < num2; j ++ )
			putchar(star);                  // 输出num2个星号
		printf("\n");                        // 换行
	}
}
