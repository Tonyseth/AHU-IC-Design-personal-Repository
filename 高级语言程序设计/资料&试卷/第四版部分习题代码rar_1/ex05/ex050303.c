#include <stdio.h>
#define SIZE 10
void main( void )
{ 
    /*****ERROR*****/
    char *ptr[SIZE];
    int i;
	
    printf("Input 10 strings:\n");
    for( i = 0; i < SIZE; i ++ )
        /*******ERROR*******/
        scanf("%s", ptr[i]);
    printf("\n");
	
    printf("Reversed strings are:\n");
    for( i = 0; i < SIZE; i ++ )
        printf("%s\n", ptr[SIZE - i - 1]); 
    printf("\n");
}
