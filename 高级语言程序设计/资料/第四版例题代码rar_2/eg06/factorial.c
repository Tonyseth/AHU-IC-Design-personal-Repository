// Program: factorial.c               	    
////////////////////////////////////////////////////////////
// Function:    double factorial( int n )
// Description: ����n�Ľ׳�
// Input:       int n��������׳˵�����n
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

