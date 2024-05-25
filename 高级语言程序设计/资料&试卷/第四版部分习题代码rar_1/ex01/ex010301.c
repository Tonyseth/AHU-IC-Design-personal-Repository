//ex010301.c

/******ERROR******/
#include <stdlib.h>//#include <stdio.h> 调用格式化输入输出函数必须嵌入 stdio.h
void main( void )
{
     int a=6, b=2, c;

     c = a;
     /***ERROR***/
     if( C < b )//if( c < b ) 变量名的大小写前后要保持一致
          c = b; 

     printf("the bigger is %d\n", c);
}
