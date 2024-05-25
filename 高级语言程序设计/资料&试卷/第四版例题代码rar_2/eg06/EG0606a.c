// 编程实现：利用一个一维数组输入10个整数，求大于等于其平均值的数组元素个数。
// 例输入: 10 20 40 32 67 56 75 88 93 100
// 输出: 5
#include <stdio.h>
void main( void )
{
	int Num[10], i, j=0, Sum=0;
	double  Avg;//Avg:平均值
	
	for( i = 0; i < 10; i ++ )
	{
		scanf("%d", &Num[i]);
		Sum += Num[i];
	}
	Avg = ( double )Sum / 10;
	for( i = 0; i < 10; i ++ )
		if( Num[i] > Avg )//比平均值高的+1
			j = j + 1;
	
	printf("%d", j);
}

