// Program: EG0412.C
// Description: 求指定二维数组中最小元素的值及其位置。
#include <stdio.h>
void main( void )
{
    int Matrix[3][4]={{  1,    6,  3, 9},
                      {  9,    8,  7, 6},
                      {  -10,  3, -5, 3}};

     int i, j, Min, RowPos, ColPos;

    Min = Matrix[0][0]; RowPos = 0; ColPos = 0;
    for( i = 0; i < 3; i ++ )
         for( j = 0; j < 4; j ++ )
              if( Min > Matrix[i][j] )
              {
                   Min = Matrix[i][j];
                   RowPos = i;
                   ColPos = j;
              }

    printf("Min=%d, row=%d, colum=%d\n", Min,
          RowPos, ColPos );
}
