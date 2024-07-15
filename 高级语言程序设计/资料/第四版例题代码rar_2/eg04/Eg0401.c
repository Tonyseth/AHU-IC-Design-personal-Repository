// Program: EG0401.C 
// Description: 输入9个整数，要求逆序打印其中的奇数。
#include <stdio.h>          				   // 包含标准I/O库函数的说明 
void main( void )           				   // 主函数说明 
{
     int num[9], i ;                            // 局部变量说明

     printf("请输入9个整数:");                  // 显示输入提示 
     for( i = 0; i < 9; i ++ )                  // 顺序输入9个整数
          scanf("%d", &num[i]);
   
     printf("逆序打印其中的奇数:");             // 显示输出提示 
     for( i = 8; i >= 0; i -- )                 // 逆序访问数组元素
          if( num[i] % 2 )                      // 判断数组元素是否为奇数
               printf(" %d", num[i]);           // 打印发现的奇数
}
