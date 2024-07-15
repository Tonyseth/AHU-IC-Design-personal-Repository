#include <stdio.h>
#define SIZE 10
void main(void)
{ 
    /*****ERROR*****/
    float *Pointer;


	printf("Input a float: ");
	scanf("%f", Pointer);

	printf("Pointer=%X *Pointer=%f\n", Pointer, *Pointer); 
}
