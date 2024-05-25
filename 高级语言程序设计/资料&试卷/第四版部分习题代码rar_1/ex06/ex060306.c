#include <stdio.h> 
void sort( int a[], int n ) 
{ 
	int i, j, t; 
	for( i = 0; i < n - 1; i ++ ) 
		for( j = i + 1; j < n; j ++ ) 
			if( a[i] < a[j] ) 
			{ 
				t = a[i]; 
				a[i] = a[j]; 
				a[j] = t; 
			} 
} 
void main(void) 
{ 
	int aa[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, i; 

	sort( &aa[3], 5 ); 

	for( i = 0; i < 10; i ++ ) 
		printf("%d,", aa[i]); 
	printf("\n"); 
} 