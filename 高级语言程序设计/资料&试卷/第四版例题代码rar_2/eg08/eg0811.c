// Program: EG0811.C 
// Description: 输入10个整数，使用fwrite函数将其存储到file6.dat中
#include <stdio.h>
#include <stdlib.h>
void main( void )
{
    FILE *fp;
    int num[6], i;
    for( i = 0; i < 6; i ++ )                // 输入6个整数
        scanf("%d", &num[i]);                

    if( ( fp = fopen( "file6.dat" , "wb" ) ) == NULL )  //  打开只写二进制文件 
    {
        printf("File can not open!\n");
        exit( 0 );
    }

	// 将存放在num数组中的6个整数写到fp指向的文件中
    fwrite( num, sizeof( int ), 6, fp ); 

    fclose( fp );                        // 关闭fp所指向的文件 
}
