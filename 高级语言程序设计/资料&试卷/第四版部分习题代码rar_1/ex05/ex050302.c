#include <stdio.h>
#define SIZE 10
void main( void )
{ 
    int Num[SIZE], *ptr=Num;
    int i;
	
    printf("Input 10 normal numbers: ");
    for( i = 0; i < SIZE; i ++ )
        scanf("%d", ptr++);
	
    printf("Inputed numbers are :");
    /*****ERROR*****/
    for( i = 0; i < SIZE; i ++ )
        printf("%d ", *ptr++);
    printf("\n");
}
