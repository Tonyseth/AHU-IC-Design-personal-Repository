// Program: combination.c  
double factorial( int n ); // �׳˺����ĺ���˵��
             	    
////////////////////////////////////////////////////////////
// Function:    int combination( int m, int n )
// Description: �������C(m,n)
// Input:       int m, int n�����������C(m,n)������m,n
// Output:      C(m,n) 
////////////////////////////////////////////////////////////
int combination( int m, int n )
{    
    return factorial( m ) / factorial( n ) / factorial( m - n );
}
