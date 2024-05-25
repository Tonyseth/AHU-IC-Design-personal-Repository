// Program: EG0410.C
// Description: 打印约瑟夫（Joseph）问题的出圈顺序表。
#include <stdio.h>
#define N 13
#define S  1
#define M  3
void main( void )
{
     int i,pos;
     int Queue[N], j=N;                //圈中有N个人
     int s=S-1;                        //从第s个人开始依次报数
     
     for( i = 0; i < N; i ++ )         //按顺时针方向围坐一圈
          Queue[i] = i;
     printf("%d个人按顺时针方向围坐一圈，从第%d个人开始依次报数，\n"\
          "数到%d的人出圈, 下一个人继续报数，直到所有人出圈为止。\n"\
          "这些人的出圈顺序表是：", N, S, M);
     
     i = 0, pos = s - 1;
     do 
     {
          pos ++;
          if( pos == N )                //数到圈尾循环访问
               pos = 0;
          if( Queue[pos] != -1 )        //数数
          {
               i ++;
               if( i == M)              //数到M的人出圈
               {
                    printf(" %d", Queue[pos] + 1);//打印出圈人
                    Queue[pos] = -1;    //出圈
                    -- j;               //人数减一
                    i = 0;              //重新计数
               }
          }
     }while( j > 0 );                   //圈中还有人吗?
     printf("\n");

}
