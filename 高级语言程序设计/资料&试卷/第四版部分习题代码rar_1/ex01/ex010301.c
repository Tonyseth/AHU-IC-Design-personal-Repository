//ex010301.c

/******ERROR******/
#include <stdlib.h>//#include <stdio.h> ���ø�ʽ�����������������Ƕ�� stdio.h
void main( void )
{
     int a=6, b=2, c;

     c = a;
     /***ERROR***/
     if( C < b )//if( c < b ) �������Ĵ�Сдǰ��Ҫ����һ��
          c = b; 

     printf("the bigger is %d\n", c);
}
