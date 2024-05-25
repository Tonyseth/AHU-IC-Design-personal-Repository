// Program: EG0507.c
// Description: 利用指针将数组Num中的元素逆序存放。
#include <stdio.h> 
#define SIZE 10
void main( void )
{
    int Num[SIZE]={ 12, 32, 28, 45, 67, 48, 18, 72, 90, 68};
    int *pBegin, *pEnd, i, tmp;

    printf("逆序前:");
    for( i = 0; i < SIZE; i ++ )
        printf(" %d", Num[i]);

    pBegin = Num;
	pEnd = Num + SIZE - 1;
    for(; pBegin < pEnd; pBegin ++, pEnd -- )
    {
        tmp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = tmp;
    }

    printf("\n逆序后:");
    for( i = 0; i < SIZE; i ++ )
        printf(" %d", Num[i]);
    printf("\n");
}
