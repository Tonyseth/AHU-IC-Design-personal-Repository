#include <stdio.h> 
#include <string.h> 
void sort( char **str, int n ) 
{ 
	char *tmp; 
	int i, j;

	for( i = 0; i < n - 1; i ++ ) 
		for( j = 0; j < n - i - 1; j ++ ) 
			if( strcmp( str[j], str[j + 1] ) > 0 ) 
				tmp = str[j], str[j] = str[j + 1], str[j + 1] = tmp; 
} 
void main(void) 
{ 
	char **ps, *str[3]={"BOOK", "COMPUTER", "CHINA"}; 
	int i; 

	ps = str; 
	sort( ps, 3 ); 
	for( i = 0; i < 3; i ++ ) 
		printf("%d %s ", i + 1, str[i]); 
} 