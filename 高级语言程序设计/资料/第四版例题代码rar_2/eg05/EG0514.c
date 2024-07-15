// Program: EG0514.c 					    
// Description: 利用字符指针数组将五门课程名按字典顺序排序输出。 
#include <stdio.h>
#include <string.h>
void main(void)
{
    char *tmp,*Str[5]={"C/C++", "Python", "MATLAB", "Authorware", "Java"};
    int i, j, k, n=5;

    for( i = 0; i < n - 1; i ++ )
    {
		k = i;
		for( j = i + 1; j < n; j ++ )
 			if( strcmp( Str[k], Str[j] ) > 0 )  
			//if( strcmp( *(Str+k), *(Str+j) ) > 0 )  
				k = j;
			if( k != i )
 				tmp = Str[i], Str[i] = Str[k], Str[k] = tmp;
				//tmp = *(Str+i), *(Str+i) = *(Str+k), *(Str+k) = tmp;
    }

    for( i = 0; i < n; i ++ )
 		puts( Str[i] );
		//puts( *(Str+i) );
}