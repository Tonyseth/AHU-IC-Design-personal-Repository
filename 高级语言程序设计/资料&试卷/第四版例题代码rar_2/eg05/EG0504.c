// Program: EG0504.c 
// Description: ����ָ�����һά���顣 
#include <stdio.h> 
void main( void )               	
{
	int Num[5]={2, 4, 6, 8, 10};
	int i, *Ptr=Num;

    printf("˳�����Num��"); 
	i = 0;
    while( i < 5 )
    {
        printf(" %d", Ptr[i]); 
        i ++;
    }

    printf("\n�������Num��"); 
    while( -- i >= 0 )
		printf(" %d", *(Ptr+i)); 
	printf("\n"); 
}


