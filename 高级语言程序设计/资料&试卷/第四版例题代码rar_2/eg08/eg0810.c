// Program: EG0810.C 
// Description: 不等长字符串的文件读写示范
#include <stdio.h>
#include <stdlib.h>
void main( void )
{
    FILE *fp;
    int i;
    char str[81];

	if( ( fp = fopen( "file5.txt", "w" ) ) == NULL )	// 打开只写的文本文件 
	{
		printf("File can not open!\n");
		exit( 0 );
	}

	for( i = 0; i < 6; i ++ )							// 循环输入6个长度不等的字符串 
	{
		fputs( gets( str ), fp );  						// 将输入的字符串写入打开的文件
		fputs( "\n", fp );  							// 写入的字符串后追加一个换行符
	}

	fclose( fp );        		 						// 关闭fp所指向的文件 

	if( ( fp = fopen( "file5.txt", "r" ) ) == NULL )	// 打开只读的文本文件 
	{
		printf("File can not open!\n");
		exit( 0 );
	}

	for( i = 0; i < 6; i ++ )   	 					// 循环读入6个长度不等的字符串 
		puts( fgets( str, 81, fp) );; 	 				// 读取1个字符串，输出到显示器 

	fclose( fp );         		 						// 关闭fp所指向的文件 */
}
