// Program: EG0604.C                       
// Description: 利用函数交换两个整数
#include <stdio.h>
void swap( int a, int b )
{
     int tmp;
     tmp = a;
     a = b;
     b = tmp;
	 //printf("函数调用中：a=%d, b=%d\n", a, b);
}
void main( void )
{
     int a=15, b=5;
     printf("函数调用前, a=%d, b=%d\n", a, b);
     if( a > b )
          swap( a, b );
     printf("函数调用后, a=%d, b=%d\n", a, b);
}

