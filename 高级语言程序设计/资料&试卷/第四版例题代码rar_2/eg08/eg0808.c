// Program: EG0808.C 
// Description: 复制文本文件
#include <stdio.h>
#include <stdlib.h>
void main( void )
{
	char fname1[81], fname2[81]; 		// 定义字符数组用来存放两个文件名
	FILE *fp1, *fp2;             			// 定义文件型指针变量用来指向两个文件

	scanf("%s%s", fname1, fname2);		// 输入源文件名和目标文件名
	if( ( ( fp1 = fopen( fname1, "r" ) ) == NULL ) )// 打开只读文本源文件
	{
		printf("File can not open!\n");
		exit( 0 );
	}
	if( ( ( fp2 = fopen( fname2, "w" ) ) == NULL ) )// 打开只写文本目标文件
	{
		printf("File can not open!\n");
		exit( 0 );
	}

	while( !feof( fp1 ) )        		//fp1尚未指向文件尾
		fputc( fgetc( fp1 ), fp2 );		//从源文件读1个字符写到目标文件中

	fclose( fp1 );           		    	//关闭fp1所指向的源文件
	fclose( fp2 );         		      	//关闭fp2所指向的目标文件
}
