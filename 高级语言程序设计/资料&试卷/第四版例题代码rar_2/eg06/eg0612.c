// Program: EG0612.c
#include <stdio.h>

////////////////////////////////////////////////////////////
// Function:    double factorial( int n )
// Description: �ݹ鷨����n�Ľ׳�
// Input:        int n��������׳˵�����n
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
