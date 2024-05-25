// Program: EG0814.C 
// Description: 文件头定位函数rewind()使用示范
#include <stdio.h>
#include <stdlib.h>
void main( void )
{
     FILE *fp;                                             // 定义文件型指针变量 
     int i;
     
     if ( ( fp = fopen( "file3.txt", "w+" ) ) == NULL )// 打开文本文件用于读写
     {
          printf("File can not open!\n");
          exit( 0 );
     }
     
     for ( i = 0; i < 20; i ++ )                       // 循环20次
          fputc( fgetc( stdin ), fp );           		// 从键盘读取字符写入文件 

     rewind( fp );                           			// 让内部指针重新指向文件头 
     for ( i = 0; i < 10; i ++ )                       // 循环10次
          fputc( fgetc( fp ), stdout);  				// 从文件中读取1个字符显示 

     fclose( fp );                                         // 关闭文件 
}


