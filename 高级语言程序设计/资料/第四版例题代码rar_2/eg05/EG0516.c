// Program: EG0516.c 					    
// Description: 输入n个单词，将其按字典顺序输出，n从键盘输入。 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLenght 31 //单词最大长度
void main(void)
{
	char tmp[MaxLenght], **words;
	int i, j, k, n=5;

	printf("请输入n：");
	scanf( "%d", &n);
	if( (words = (char **) malloc( sizeof(char *)*n )) == NULL )
	{
		printf( "内存分配失败\n" );
		return ;
	}
	
	for( i = 0; i < n; i ++ )
	{
		printf("请输入第%d个单词：", i + 1);
		scanf( "%s", tmp);
		if( ( words[i] = (char *) malloc( sizeof(char)*( strlen(tmp) + 1 ) ) ) == NULL )
		{
			printf( "第%d个单词内存分配失败\n", i + 1);
			return ;
		}
		strcpy( words[i], tmp );
	}
	
	for( i = 0; i < n - 1; i ++ )
	{
		k = i;
		for( j = i  +1; j < n; j ++)
			if( strcmp( words[k], words[j] )>0 )  
				k = j;
		if( k != i )
		{
			char *tmp;
			tmp = words[i], words[i] = words[k], words[k] = tmp;
		}
	}
	
	printf( "排序结果\n");
	for( i = 0; i < n; i ++ )
		puts( words[i] );
	
	//for( i = 0; i < n; i ++ )
		//free( *(words+i) );
	free( words );
}
