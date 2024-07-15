// Program: EG0612.c
#include <stdio.h>

////////////////////////////////////////////////////////////
// Function:    double factorial( int n )
// Description: 递归法计算n的阶乘
// Input:        int n：待计算阶乘的整数n
// Output:       n! 
////////////////////////////////////////////////////////////  
double factorial( int n )
{
    if( n < 0 )
    {
        printf("n<0, input error!");
        return -1.0;
    }
    if( n == 0 || n == 1 )
        return 1.0;
    return  factorial( n - 1 ) * n;
}
