#include <stdio.h>
#include <stdlib.h>						// 包含rand()函数说明
#include <time.h>

void main(void)
{
	int i, j, num[10], tmp;
	   
    // 用当前时间种子重置随机数生成器，使每次运行生成不同的随机数
	srand( (unsigned)time( NULL ) );

	for(i=0; i<10; i++) 				// 生成10个数
	{
        while(1) 						// 生成1个数
        {
			tmp=10 *rand()/RAND_MAX +1; // 产生随机数
			for(j=0; j<i; j++) 			// 判断是否重复
				if(tmp==num[j])
					break;
			if(j==i) 					// 找到1个数
			{
				num[i]=tmp; 			// 入队列
				break; 					// 开始下一轮
			}
        }
        printf("%d,", num[i]); 			// 打印结果
	}
	printf("\b \n"); 
}
