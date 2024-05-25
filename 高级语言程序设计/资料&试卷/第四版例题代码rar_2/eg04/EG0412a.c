// Program: EG0412.C
// Description: 求指定二维数组中最小元素的值及其位置。
#include <stdio.h>
void main( void )
{
    int Matrix[3][4]={{  1,    6,  3, 9},
                      {  9,    8,  7, 6},
                      {  -10,  3, -5, 3}};
     int i, j, Max, Min, RowPos, ColPos, flag=0;// flag=0表示没有鞍点

     for( i = 0; i < 3; i ++ )
     {
           Max = Matrix[i][0]; 
           for( j = 0; j < 4; j ++ )
                 if( Matrix[i][j] > Max )
                 {
                       Max = Matrix[i][j];
                       ColPos = j;
                 }
           Min = Matrix[0][ColPos]; // 寻找第i行最大值对应列最小值
           for( j = 0; j < 3; j ++ )
                 if( Matrix[j][ColPos] < Min )
                 {
                       Min = Matrix[j][ColPos];
                       RowPos = j;
                 }
           if( Max == Min ) // 两者相同，发现鞍点
           {
                 printf("found %d in (%d, %d)\n", Max, RowPos, ColPos);
                 flag = 1; // 标记已经发现鞍点
           }
      }
     if( flag == 0 ) //一直没有发现鞍点，输出对应提示
     {
            printf("not found\n");
     }

}
