// Program: EG06017.C
// Description: ����qsort()��һ����������С��������
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
// Description: �Ƚ�ָ��������������qsort�涨ָ�������void *����ʱ��ת��
// Input:       void *p,  void *q ��ָ���������Ƚϵ�������ָ��
// Output:      ���رȽϽ����>0��==0��<0
/////////////////////////////////////////////////////////////////////////
int comp( void *p,  void *q )
{
    return *(int *)p - *(int *)q;
}
