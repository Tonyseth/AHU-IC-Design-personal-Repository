// Program: EG0609.c
////////////////////////////////////////////////////////////
// Function:    int sign( int x )
// Description: ���ź���sign����x�ķ���
// Input:        int x�����ж����� 
// Output:       ��x>0������1����x==0������0����x<0������-1
////////////////////////////////////////////////////////////
int sign( int x )
{
    if( x > 0 )
        return 1;
    if( x == 0 )
        return 0;
    if( x < 0 )
        return -1;
}

