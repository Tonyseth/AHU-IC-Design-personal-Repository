// Program: EG0807.C 
// Description: 输入file3.txt前10个字符。
#include <stdio.h>
#include <stdlib.h>
void main()
{
    FILE *fp1;                                 		 /* 定义文件型指针变量 */
    int i;
    char ch;

    if( ( fp1 = fopen( "file3.txt", "r" ) ) == NULL )/* 打开文本文件用于读 */
    {
        printf("File can not open!\n");
        exit( 0 );
    }

    for( i = 0; i < 10; i ++ )                    	 /* 循环10次 */
    {
        ch = fgetc( fp1 );        					 /* 从文件中读取1个字符存入变量ch */
        putchar( ch );    							 /* 将变量ch中字符输出到显示器 */
    }

    fclose( fp1);                            		 /* 关闭文件 */
}
