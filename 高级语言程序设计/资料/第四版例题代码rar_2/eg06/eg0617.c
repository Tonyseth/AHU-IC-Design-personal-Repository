// Program: EG06017.C
// Description: 调用qsort()对一组整型数从小到大排序
#include <stdio.h>
#include <stdlib.h>
#define SIZE   8
int comp( void *, void * );

void main( void )
{
    int i;
    int Num[SIZE]={ 5, 6, 8, 2, 9, 1, 3, 0};

    qsort( Num, SIZE, sizeof(int), comp );

    for( i = 0; i < SIZE; i ++ )
        printf("%d ", Num[i]);
    printf("\n");
}

/////////////////////////////////////////////////////////////////////////
// Function:    int comp( void *p,  void *q )
// Description: 比较指定的两个整数，qsort规定指针必须是void *，用时需转换
// Input:       void *p,  void *q ：指向两个待比较的整数的指针
// Output:      返回比较结果：>0、==0、<0
/////////////////////////////////////////////////////////////////////////
int comp( void *p,  void *q )
{
    return *(int *)p - *(int *)q;
}
