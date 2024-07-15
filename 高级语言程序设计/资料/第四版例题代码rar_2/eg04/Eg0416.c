// Program: EG0416.C 
// Description: 编程将10名同学的姓名和考试成绩按姓名递增排序。
#include <stdio.h>
#include <string.h>
void main( void )
{
    char Names[10][10]={"张三", "李四", "赵一", "周五", "钱二", "孙三", "王二",
                        "冯九","吴六","郑七"}, NameTmp[10];

	int Scores[10]={95, 74, 83, 90, 66, 89, 70, 92, 73, 86}, ScoreTmp;
    unsigned int i, j; 
 
	for( i = 0; i < 10; i ++ )
		for( j = 0; j < 10 - i - 1; j ++ )
			if( strcmp(Names[j], Names[j + 1]) > 0 )
			{
				strcpy( NameTmp, Names[j] );
				strcpy( Names[j], Names[j + 1] );
				strcpy( Names[j + 1], NameTmp );
				ScoreTmp = Scores[j];
				Scores[j] = Scores[j + 1];
				Scores[j + 1] = ScoreTmp;
			}

	printf("The shorted data is :\n");
	for( i = 0; i < 10; i ++ )
		printf("%s\t%d\n", Names[i], Scores[i]);
}
