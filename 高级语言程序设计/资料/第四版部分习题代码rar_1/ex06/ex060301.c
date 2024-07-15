#include <stdio.h> 
void main(void) 
{ 
	int x=1; 
	{ 
		int x=2; 
		{ 
			int x=3; 
			printf("%2d", x); 
		} 
		printf("%2d", x); 
	} 
	printf("%2d", x); 
} 