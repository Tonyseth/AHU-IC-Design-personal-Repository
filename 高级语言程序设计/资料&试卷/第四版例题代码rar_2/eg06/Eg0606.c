// Program: EG0606.c
// Description:  ��д����funͳ��ָ�������д��ڵ���ƽ��ֵ������Ԫ�ظ�����
#include <stdio.h>

////////////////////////////////////////////////////////////
// Function:    void fun( int *Num, int Size, int *num )
// Description: ͳ��ָ�������д��ڵ���ƽ��ֵ������Ԫ�ظ���
// Input:       int *Num��ָ��������ʼԪ�ص�ָ��
//              int size������Ԫ�ظ���
//              int *num��ָ��ͳ�ƽ����ָ��
// Output:      ��
////////////////////////////////////////////////////////////  
void fun( int *Num, int Size, int *num )
{
    int i, Sum=0;
	double Avg;//Avg:ƽ��ֵ
  
    for( i = 0; i < Size; i ++ )
        Sum += Num[i];
	Avg = ( double )Sum / Size;
	for( *num = i = 0; i < Size; i ++ )
		if( Num[i] > Avg ) //��ƽ��ֵ�ߵ�+1
			*num += 1;
}
void main( void )
{
    int Num[10], i, count=0;

    for( i = 0; i < 10; i ++ )
		scanf("%d", Num + i);

    fun( Num, 10, &count );

    printf("%d\n", count);
}	
 