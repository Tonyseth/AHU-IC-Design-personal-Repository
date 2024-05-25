// Program: EG0408.C
// Description: 在指定的整数数组中删除输入的数x
#include <stdio.h>
void main( void )
{
	int Num[]={12, 81, 22, 72, 12, 33, 68, 36, 12, 56};
	int i, j, x, flag=0, n;

	printf("请输入要删除的数：");
	scanf("%d", &x);

	n=sizeof(Num)/sizeof(int); //求数组长度
	printf("删除前数组为：");
	for(i=j=0; i<n; i++)
		printf(" %d", Num[i]);
	printf("\n");

	for(i=0; i<n; i++)
		if( Num[i] != x )
		{
			Num[j] = Num[i]; 			
			j++;
		}
		else
			flag=1;

	if( flag == 1 )
	{
		printf("删除后数组为：");
		n=j;
		for(i=0; i<n; i++)
			printf(" %d", Num[i]);
		printf("\n");
	}
	else
		printf("未找到%d!\n", x);
}
