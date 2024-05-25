// Program: factorial.c               	    
////////////////////////////////////////////////////////////
// Function:    double factorial( int n )
// Description: 计算n的阶乘
// Input:       int n：待计算阶乘的整数n
// Output:      n! 
////////////////////////////////////////////////////////////  
double factorial( int n )
{
    double fac=1;
	int i=1;

    while( i <= n )
	{
		fac *= i;
		i ++;
	}
	
    return fac;
}

