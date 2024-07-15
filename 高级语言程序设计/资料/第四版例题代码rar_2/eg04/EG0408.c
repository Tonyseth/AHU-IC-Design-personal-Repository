// Program: EG0408.C
// Description: 在指定的整数数组中删除输入的数x
#include <stdio.h>
void main( void )
{
	int Num[]={12, 81, 22, 12, 12, 33, 68, 36, 12, 56};
	int i, j, x, flag=0, n;

	printf("请输入要删除的数：");
	scanf("%d", &x);

	n = sizeof(Num) / sizeof(int); //求数组长度
	printf("删除前数组为：");
	for( i = 0; i < n; i ++ )
		printf(" %d", Num[i]);
	printf("\n");

	for( i = 0; i < n; i ++ )
		if( x == Num[i] ) //发现待删除数
		{
			for( j = i; j < n - 1; j ++ )
				Num[j] = Num[j + 1]; //其后所有元素依次前移
			flag = 1; //删除标志改为真
			i --; //为避免移过来的数也是待删除数，需要重新检查当前数组元素
			n --; //已删除了一个数，数组长度要减一
		}

	if( flag == 1 )
	{
		printf("删除后数组为：");
		for( i = 0; i < n; i ++ )
			printf(" %d", Num[i]);
		printf("\n");
	}
	else
		printf("未找到%d!\n", x);
}
