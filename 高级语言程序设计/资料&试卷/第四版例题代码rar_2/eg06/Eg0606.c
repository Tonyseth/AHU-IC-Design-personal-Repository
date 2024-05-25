// Program: EG0606.c
// Description:  编写函数fun统计指定数组中大于等于平均值的数组元素个数。
#include <stdio.h>

////////////////////////////////////////////////////////////
// Function:    void fun( int *Num, int Size, int *num )
// Description: 统计指定数组中大于等于平均值的数组元素个数
// Input:       int *Num：指向数组起始元素的指针
//              int size：数组元素个数
//              int *num：指向统计结果的指针
// Output:      无
////////////////////////////////////////////////////////////  
void fun( int *Num, int Size, int *num )
{
    int i, Sum=0;
	double Avg;//Avg:平均值
  
    for( i = 0; i < Size; i ++ )
        Sum += Num[i];
	Avg = ( double )Sum / Size;
	for( *num = i = 0; i < Size; i ++ )
		if( Num[i] > Avg ) //比平均值高的+1
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
 