// Program: EG0410.C
// Description: ��ӡԼɪ��Joseph������ĳ�Ȧ˳���
#include <stdio.h>
#define N 13
#define S  1
#define M  3
void main( void )
{
     int i,pos;
     int Queue[N], j=N;                //Ȧ����N����
     int s=S-1;                        //�ӵ�s���˿�ʼ���α���
     
     for( i = 0; i < N; i ++ )         //��˳ʱ�뷽��Χ��һȦ
          Queue[i] = i;
     printf("%d���˰�˳ʱ�뷽��Χ��һȦ���ӵ�%d���˿�ʼ���α�����\n"\
          "����%d���˳�Ȧ, ��һ���˼���������ֱ�������˳�ȦΪֹ��\n"\
          "��Щ�˵ĳ�Ȧ˳����ǣ�", N, S, M);
     
     i = 0, pos = s - 1;
     do 
     {
          pos ++;
          if( pos == N )                //����Ȧβѭ������
               pos = 0;
          if( Queue[pos] != -1 )        //����
          {
               i ++;
               if( i == M)              //����M���˳�Ȧ
               {
                    printf(" %d", Queue[pos] + 1);//��ӡ��Ȧ��
                    Queue[pos] = -1;    //��Ȧ
                    -- j;               //������һ
                    i = 0;              //���¼���
               }
          }
     }while( j > 0 );                   //Ȧ�л�������?
     printf("\n");

}
