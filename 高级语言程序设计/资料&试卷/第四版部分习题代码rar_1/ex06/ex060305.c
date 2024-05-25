#include <stdio.h> 
char fun( char x, char y ) 
{ 
	char m; 
	if( x > y )
		m = x; 
	m = y; 
	return m; 
} 
void main(void) 
{ 
	int a='9', b='8', c= '7'; 
	printf("%c\n", fun( fun( a, b ), fun( b, c ) )); 
} 