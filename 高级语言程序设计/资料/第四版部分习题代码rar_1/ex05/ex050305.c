#include <stdio.h>
#include <string.h>
void main( void )
{
    char *tmp, *str[5]={"VB","FORTRAN","VC++","Authorware","Java"};
    int i, j, k, n=5;

    for( i = 0; i < n - 1; i ++ )
    {
        k = i;
        for( j = i + 1; j < n; j ++ )
            if( strcmp( str[k], str[j] ) > 0 )  
                k = j;
		if( k != i )
		{
			/*******ERROR*******/
			strcpy( tmp, str[i] );
			strcpy( str[i], str[k] );
			strcpy( str[k], tmp );
		}
    }

    for( i = 0; i < n; i ++ )
        puts( str[i] );
}
