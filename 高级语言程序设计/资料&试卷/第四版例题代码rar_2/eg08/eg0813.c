// Program: EG0813.C 
// Description: 格式数据的文件读写示范
#include <stdio.h>
#include <stdlib.h>
void main( void )
{
     FILE *fp;
     char ch, ch0, str[81], str0[81];
     int i, i0;
     double r, r0;

     if( ( fp = fopen( "file8.txt", "w" ) ) == NULL )    // 打开只写文本文件 
     {
          printf("File can not open!\n");
          exit( 0 );
     }
     scanf("%c", &ch);                       	// 从键盘读取1个字符 
     scanf("%d,", &i);              			// 从键盘读取2个短整数 
     scanf("%lf,", &r);                  		// 从键盘读取5个双精度实数 
     scanf("%s", str);                   		// 从键盘读取6个字符串 
     // 将1个字符、1个整数、1个实数、1个字符串按指定格式写入fp指向的文件 
     fprintf( fp, "%c%d,%f,%s\n", ch, i, r, str );
     fclose( fp );                       		// 关闭fp所指向的文件 

     if( ( fp = fopen( "file8.txt", "r" ) ) == NULL )    // 打开只写文本文件 
     {
          printf("File can not open!\n");
          exit( 0 );
     }
     fscanf( fp,"%c", &ch0 );              	// 从文件中读取1个字符 
     fscanf( fp,"%d,", &i0 );              	// 从文件中读取1个整数 
     fscanf( fp,"%lf,", &r0 );             	// 从文件中读取1个实数 
     fscanf( fp, "%s", str0 );      		// 从文件中读取1个字符串 
	     // 输出从文件中读取的数据 
     printf("%c\n%d\n%f\n%s\n", ch0, i0, r0, str0);
     fclose( fp );                        		// 关闭fp所指向的文件 
}

