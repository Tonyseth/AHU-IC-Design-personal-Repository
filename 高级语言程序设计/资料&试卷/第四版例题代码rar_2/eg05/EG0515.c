// Program: EG0515.c 					    
// Description: ACM 数字调序 
#include <stdio.h>
#include <stdlib.h>
void main(void)
{
	int *Num, i, j, n, m;

	scanf("%d", &n);
	if( (Num =(int *) malloc( sizeof(int)*n )) == NULL )
	{
		printf( "内存分配失败\n" );
		return ;
	}	
	for( i = 0; i < n; i ++ )
		scanf("%d", Num + i);
	scanf("%d", &m);
	
	while( m-- )
	{
		j = *( Num + n - 1 );
		//for( i = 0; i < n - 1; i ++ )
		//	*( Num +  n - 1 - i ) = *( Num + n - 2 - i );
		for( i = n - 1; i > 0; i -- )
			*( Num  + i ) = *( Num + i -1 );
		*Num = j ;
	}
 	
	for( i = 0; i < n; i ++ )
		printf("%d ", *( Num + i ) );

	free( Num );
}
