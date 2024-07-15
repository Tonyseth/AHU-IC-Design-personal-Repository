// Program: combination.c  
double factorial( int n ); // 阶乘函数的函数说明
             	    
////////////////////////////////////////////////////////////
// Function:    int combination( int m, int n )
// Description: 计算组合C(m,n)
// Input:       int m, int n：待计算组合C(m,n)的整数m,n
// Output:      C(m,n) 
////////////////////////////////////////////////////////////
int combination( int m, int n )
{    
    return factorial( m ) / factorial( n ) / factorial( m - n );
}
