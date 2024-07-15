// Program: EG0815.C 
// Description: 随机定位函数fseek()使用示范
#include <stdio.h>
#include <stdlib.h>
void main( void )
{
     FILE *fp;
     int x, i;
     
     if ( ( fp = fopen( "file9.dat ", "wb+" ) ) == NULL )// 打开二进制文件读写
     {
          printf("File can not open!\n");
          exit( 0 );
     }
     for ( i = 1; i <= 20; i ++ )                   // 循环20次
          fwrite( &i, sizeof( int ), 1, fp );   	// 将i写入文件 
     
     fseek(fp, 0L, SEEK_SET);                     // 定位到文件头 
     for ( i = 0; i < 3; i ++ )                   // 循环读取第1、3、5个整数
     {
          fread( &x, sizeof( int ), 1, fp );   	// 从当前位置读取1个整数 
          printf("%d ", x);                			// 输出读取的1个整数 
          fseek( fp, (long)sizeof(int), SEEK_CUR ); // 定位到下一个整数
     }
     fseek( fp, (long)sizeof(int)*11, SEEK_SET ); // 定位到第12个整数 
     fread( &x, sizeof( int ), 1, fp );   		// 读取第12个整数 
     printf("%d ", x);                				// 输出读取的第12个整数 
     fseek(fp, -1*(long)sizeof(int), SEEK_END); // 定位到第20个整数
     fread( &x, sizeof( int ), 1, fp );   		// 读取第20个整数
     printf("%d ", x);                				// 输出读取的第20个整数 

     fclose( fp );                            		// 关闭fp所指向的文件 
}



