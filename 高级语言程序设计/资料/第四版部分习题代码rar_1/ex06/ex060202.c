#include <stdio.h>
int atoi( char str[] )
{
    int value=0, i=0;

    while( str[i] != '\0' )
    {
        value = value * 10 + str[i] - '0';
        i++;
    }

    return value;
}
void main( void )
{
   printf("%d\n", atoi( "512" ));
}
