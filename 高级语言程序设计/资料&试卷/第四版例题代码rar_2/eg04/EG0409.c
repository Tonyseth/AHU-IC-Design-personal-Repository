// Program: EG0409.C 
// Description: ʵ��ָ������������
#include <stdio.h>
void main( void )
{
     int Num[1000];
     int i, j, n, tmp;

     scanf("%d", &n); // ��������Ԫ�صĸ���n��1<n<1000)
     for( i = 0; i < n; i ++ ) // ˳����������Ԫ��
          scanf("%d", &Num[i]);

     i = 0, j = n - 1;
     while( i < j ) // ��βԪ��������������
     {
          tmp = Num[i];
          Num[i] = Num[j];
          Num[j] = tmp;
          ++ i, -- j; // i++ָ����һ��Ԫ�أ�j--ָ��ǰһ��Ԫ��
     }

     for( i = 0; i < n; i ++ ) // ��ӡ����������
          printf("%d ", Num[i]);
     printf("\n");

}
