// Program: EG0617.C                       
// Description: ��ʾ������������Ĳ����� 

#include <stdio.h>

void main( int argc, char *argv[] )
{
	short i=0;
	while(i<argc)
	{
		printf("����%d->%s\n", i, argv[i]);
		i++;
	}
	getchar();
}
