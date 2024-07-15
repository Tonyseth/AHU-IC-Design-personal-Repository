// Program: EG0409.C 
// Description: 实现指定的数组逆序
#include <stdio.h>
void main( void )
{
     int Num[1000];
     int i, j, n, tmp;

     scanf("%d", &n); // 输入数组元素的个数n（1<n<1000)
     for( i = 0; i < n; i ++ ) // 顺序输入数组元素
          scanf("%d", &Num[i]);

     i = 0, j = n - 1;
     while( i < j ) // 首尾元素依次两两互换
     {
          tmp = Num[i];
          Num[i] = Num[j];
          Num[j] = tmp;
          ++ i, -- j; // i++指向下一个元素，j--指向前一个元素
     }

     for( i = 0; i < n; i ++ ) // 打印逆序后的数组
          printf("%d ", Num[i]);
     printf("\n");

}
