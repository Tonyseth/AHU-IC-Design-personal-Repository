// Program: EG0412.C
// Description: ��ָ����ά��������СԪ�ص�ֵ����λ�á�
#include <stdio.h>
void main( void )
{
    int Matrix[3][4]={{  1,    6,  3, 9},
                      {  9,    8,  7, 6},
                      {  -10,  3, -5, 3}};
     int i, j, Max, Min, RowPos, ColPos, flag=0;// flag=0��ʾû�а���

     for( i = 0; i < 3; i ++ )
     {
           Max = Matrix[i][0]; 
           for( j = 0; j < 4; j ++ )
                 if( Matrix[i][j] > Max )
                 {
                       Max = Matrix[i][j];
                       ColPos = j;
                 }
           Min = Matrix[0][ColPos]; // Ѱ�ҵ�i�����ֵ��Ӧ����Сֵ
           for( j = 0; j < 3; j ++ )
                 if( Matrix[j][ColPos] < Min )
                 {
                       Min = Matrix[j][ColPos];
                       RowPos = j;
                 }
           if( Max == Min ) // ������ͬ�����ְ���
           {
                 printf("found %d in (%d, %d)\n", Max, RowPos, ColPos);
                 flag = 1; // ����Ѿ����ְ���
           }
      }
     if( flag == 0 ) //һֱû�з��ְ��㣬�����Ӧ��ʾ
     {
            printf("not found\n");
     }

}
