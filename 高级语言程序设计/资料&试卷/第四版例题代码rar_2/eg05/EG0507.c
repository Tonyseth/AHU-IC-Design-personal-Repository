// Program: EG0507.c
// Description: ����ָ�뽫����Num�е�Ԫ�������š�
#include <stdio.h> 
#define SIZE 10
void main( void )
{
    int Num[SIZE]={ 12, 32, 28, 45, 67, 48, 18, 72, 90, 68};
    int *pBegin, *pEnd, i, tmp;

    printf("����ǰ:");
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

    printf("\n�����:");
    for( i = 0; i < SIZE; i ++ )
        printf(" %d", Num[i]);
    printf("\n");
}
