// Program: EG0413.C
// Description: ����strcat()������ʵ�ֶ����������ַ��������ӡ�
#include <stdio.h>
void main( void )
{
     char str1[20], str2[10];
     int  i=0, j=0;

     printf("���������ַ���:\n");
     gets( str1 );
     gets( str2 );

      while( str1[i] != '\0' )  //str1[i] != 0 //str1[i]
            i ++;
      while( str1[i + j] = str2[j] )
            j ++;

     printf("str1=%s\n", str1);
}

