// Program: EG0609.c
////////////////////////////////////////////////////////////
// Function:    int sign( int x )
// Description: ∑˚∫≈∫Ø ˝sign∑µªÿxµƒ∑˚∫≈
// Input:        int x£∫¥˝≈–∂œ’˚ ˝ 
// Output:       »Ùx>0£¨∑µªÿ1£ª»Ùx==0£¨∑µªÿ0£ª»Ùx<0£¨∑µªÿ-1
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

