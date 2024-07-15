#include <stdio.h>
void maxval( int num[4][4] )
{
    int i, j, max, row=0, col=0;

    max = num[0][0];
    for( i = 0; i < 4; i ++ )
        for( j = 0; j < 4; j ++ )
            if( max < num[i][j] )
            {
                max = num[i][j] ;
                row = i ;
                col = j ;
            }

    printf("The max one is num[%d][%d]=%d:\n", row, col, max);
}
void main( void )
{
    int Num[4][4]= {{ 32,  12, 78, 45},
					{ 12,  56, 32, 88},
					{ 13,  22, 87, 54},
					{ 73, 122, 73, 65}};
	maxval( Num );
}
