// Program: EG0617.C                       
// Description: 显示命令行中输入的参数。 

#include <stdio.h>

void main( int argc, char *argv[] )
{
	short i=0;
	while(i<argc)
	{
		printf("参数%d->%s\n", i, argv[i]);
		i++;
	}
	getchar();
}
