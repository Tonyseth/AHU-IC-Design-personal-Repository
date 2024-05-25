#include <stdio.h>
void insert( float num[13], float new )
{
    int i=11;

    num[12] = new;
    while( i >= 0 && num[i] < num[i+1] )
    {
        new = num[i+1];
        num[i+1] = num[i];
        num[i] = new;
        i --;
    }
}
void main( void )
{
    float Num[13]={255, 222, 178, 145, 112, 96, 88,
					63, 52, 37, 21, 8};
	int i;

	insert( Num, 132.5 );

    for( i = 0; i < 13; i ++ )
	    printf("%6.2f", Num[i]);
}
