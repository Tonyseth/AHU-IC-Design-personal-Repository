// Program: EG0809.C 
// Description: 等长字符串的文件读写示范
#include <stdio.h>
#include <stdlib.h>
void main( void )
{
	FILE *fp;
	int i;
	char str[4][13]={"春眠不觉晓，","处处闻啼鸟。","夜来风雨声，","花落知多少。"};

	if( ( fp = fopen( "file4.txt", "w" ) ) == NULL )	// 打开只写的文本文件 
	{
		printf("File can not open!\n");
		exit( 0 );
	}

	for( i = 0; i < 4; i ++ )							// 循环输入4句唐诗 
		fputs( str[i], fp );  							// 将输入唐诗写入文件

	fclose( fp );        		 						// 关闭fp所指向的文件 

	if( ( fp = fopen( "file4.txt", "r" ) ) == NULL )	// 打开只读的文本文件 
	{
		printf("File can not open!\n");
		exit( 0 );
	}

	for( i = 0; i < 4; i ++ )   	 					// 循环读取4句唐诗 
	{
		fgets( str[i], 13, fp); 	 					// 读取一句12个字符
		puts( str[i] );            		 				// 将字符串输出显示 
	}

	fclose( fp );         		 						// 关闭fp所指向的文件 */
}
