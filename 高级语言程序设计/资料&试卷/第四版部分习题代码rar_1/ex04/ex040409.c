#include <stdio.h> 
#include <string.h>
void main( void )
{
    char Nation[5][10];
    char temp[10];
    int i, j;
	
    puts("请输入5个国家名：");
    for (i=0; i<5; i++)
        gets(Nation[i]);
	
    for (i=0; i<4; i++)
        for (j=0; j<4-i; j++)
            if ( strcmp(Nation[j], Nation[j+1])>0)
            {
                strcpy(temp, Nation[j]);
                strcpy(Nation[j], Nation[j+1]);
                strcpy(Nation[j+1], temp);
            }
			
	puts("排序结果：");
	for (i=0; i<5; i++)
		printf("%s ",Nation[i]);
	printf("\n");
}
