#include <stdio.h> 
void f( int x, int y )
{
     int t;
     if( x < y )
     {
          t = x;
          x = y;
          y = t;
     }
}
void main( void )
{
     int a=4, b=3, c=5;
     f( a, b );
     f( a, c );
     f( b, c );
     printf("%d,%d,%d\n", a, b, c);
}
