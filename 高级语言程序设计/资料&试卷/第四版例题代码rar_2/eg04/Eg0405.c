// Program: EG0405.C
// Description: 对10个浮点数按从小到大顺序进行冒泡法排序。
#include <stdio.h>
#define SIZE 10
void main(void)
{
     float Num[SIZE]={11.2, 32.1, 25.8, 4.5, 6.7, 4.8, 18, 27.2, 19, 6.8}, tmp;
     int i, j;

     printf("Normal numbers:");
     for( i = 0; i < SIZE; i ++ )
           printf("%5.1f", Num[i]);
     printf("\n");

     for( i = 0; i < SIZE - 1; i ++ )
     {
           for( j = 0; j < SIZE - i - 1; j ++ )
                if( Num[j] > Num[j + 1] )
                     tmp = Num[j], Num[j] = Num[j+1], Num[j+1] = tmp;
     }

     printf("Sorted numbers:");
     for( i = 0; i < SIZE; i ++ )
           printf("%5.1f", Num[i]);
     printf("\n");
}
