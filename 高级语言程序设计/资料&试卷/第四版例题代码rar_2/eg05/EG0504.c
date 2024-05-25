// Program: EG0504.c 
// Description: 利用指针访问一维数组。 
#include <stdio.h> 
void main( void )               	
{
	int Num[5]={2, 4, 6, 8, 10};
	int i, *Ptr=Num;

    printf("顺序访问Num："); 
	i = 0;
    while( i < 5 )
    {
        printf(" %d", Ptr[i]); 
        i ++;
    }

    printf("\n逆序访问Num："); 
    while( -- i >= 0 )
		printf(" %d", *(Ptr+i)); 
	printf("\n"); 
}


