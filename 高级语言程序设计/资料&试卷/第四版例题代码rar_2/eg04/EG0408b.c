// Program: EG0408b.C
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

	for( i = j = 0; i < n; i ++ )
		if( Num[i] != x ) //发现非删除数
		{
			Num[j] = Num[i]; //非删除数向前覆盖
			j++;
		}
		else
			flag = 1;
	n = j; //最终数组长度等于非删除数个数+1

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
