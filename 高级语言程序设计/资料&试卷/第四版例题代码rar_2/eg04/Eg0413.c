// Program: EG0413.C
// Description: 不用strcat()函数，实现对输入两个字符串的连接。
#include <stdio.h>
void main( void )
{
     char str1[20], str2[10];
     int  i=0, j=0;

     printf("输入两个字符串:\n");
     gets( str1 );
     gets( str2 );

      while( str1[i] != '\0' )  //str1[i] != 0 //str1[i]
            i ++;
      while( str1[i + j] = str2[j] )
            j ++;

     printf("str1=%s\n", str1);
}

