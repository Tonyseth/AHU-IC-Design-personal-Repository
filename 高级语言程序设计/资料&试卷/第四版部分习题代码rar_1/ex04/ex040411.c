// Program: ex040411.C
// Description: ≤Â»Î≈≈–Ú
#include <stdio.h>
#define SIZE 10
void main( void )
{
    int Num[SIZE]={12,22,33,36,48,56,68,72,81};
    int i, j, tmp;

    printf("input numbers:");
    for(i=0; i<SIZE; i++)
         scanf("%d", &Num[i]);

    for( i=0; i<SIZE; i++ )
		for( j=0; j<i-1; j++ )
			  if( Num[j]>Num[i-1] )
				   tmp=Num[j],Num[j]=Num[i-1],Num[i-1]=tmp;

    printf("Sorted numbers:");
    for(i=0; i<SIZE; i++)
         printf("%5d", Num[i]);
    printf("\n");
}
