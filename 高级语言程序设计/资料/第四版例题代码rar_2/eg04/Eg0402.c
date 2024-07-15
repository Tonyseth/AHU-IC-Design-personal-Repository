// Program: EG0402a.C
// Description: 输入一个正整数，逆序打印其各位数字
#include <stdio.h>
void main( void )
{    
     int num;
	 int digit[8], i, j;

     printf("请输入一个正整数:");
     scanf("%d", &num);
	 
     for( i = 0; num != 0; i ++ )
     {
		 digit[i] = num % 10;
		 num /= 10;
     }

     printf("颠倒的各位数字是：");
	 for( j = 0 ; j < i-1; j ++ )
		 printf("%2d,", digit[j]);
     printf("%2d\n", digit[j]);
}