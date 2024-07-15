// Program: EG0806.C 
// Description: 输入20个字符，写入file3.txt中。
#include <stdio.h>
#include <stdlib.h>
void main()
{
    FILE *fp1;                                 		 /* 定义文件型指针变量 */
    int i;
    char ch;

    if( ( fp1 = fopen( "file3.txt", "w" ) ) == NULL )/* 打开文本文件用于写 */
    {
        printf("File can not open!\n");
        exit( 0 );
    }

    for( i = 0; i < 20; i ++ )                    	 /* 循环20次 */
    {
        ch = getchar();    							 /* 从键盘读取字符 */
        fputc( ch, fp1 );    						 /* 写入文件 */
    }

    fclose( fp1);                            		 /* 关闭文件 */
}
