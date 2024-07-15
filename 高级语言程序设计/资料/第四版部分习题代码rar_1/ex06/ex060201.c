#include <stdio.h>
void fun( int n )
{
    int i;

    printf("%d=", n);
    for( i = 2; i <= n; i ++ )
        while( n != i )
        {
            if( n % i == 0 )
            {
                printf("%d*", i);
                n = n / i;
            }
            else
                break ;
        }
    printf("%d", n);
}
void main( void )
{
   fun(225);
}
