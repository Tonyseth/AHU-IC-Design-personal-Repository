// Program: EG0402a.C
// Description: ����һ���������������ӡ���λ����
#include <stdio.h>
void main( void )
{    
     int num;
	 int digit[8], i, j;

     printf("������һ��������:");
     scanf("%d", &num);
	 
     for( i = 0; num != 0; i ++ )
     {
		 digit[i] = num % 10;
		 num /= 10;
     }

     printf("�ߵ��ĸ�λ�����ǣ�");
	 for( j = 0 ; j < i-1; j ++ )
		 printf("%2d,", digit[j]);
     printf("%2d\n", digit[j]);
}