#include <stdio.h>
//设置阶乘位数上限为1000
#define N 1000
void main(void)
{
	int r[N]={1}; // 阶乘按位逆序存放在每个数组元素中
	int i, j;
	int k=0, l=0; // k存储进位数字，l存储从0开始计数的阶乘位数
	for(i=1; i<=40; i++)
	{		
		for(j=0; j<=l; j++)
		{			
			r[j]=r[j]*i+k;	// 逐位*i，加上原来的进位
			k=r[j]/10;		// 本次进位
			r[j]=r[j]%10;	// 本位			
		}
		while(k)			// 存在进位
		{
			l++;			// 增加阶乘位数
			r[j++]=k%10;	// 处理个位进位
			k=k/10;			// 进位右移，处理更多进位
		}		
		j=l;				// 打印逆序存放的阶乘
		printf("%d!=%d", i, r[j]);
		for(--j; j>=0; j--)
		{
			printf("%d", r[j]);
		}
		printf("\n");
	}
}
