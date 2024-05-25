// Program: EG0502.c 					    
// Description: 演示指针变量与存取运算 
#include <stdio.h> 
void main( void )               	
{
	int Num=0x01234567;
	int *Ptr=&Num;     		

	printf("Num=%x in %x\n", Num, &Num);  
	printf("*Ptr=%x, Ptr=%x in %x\n", *Ptr, Ptr, &Ptr);  
	printf("*&Num=%x &*Ptr=%x\n", *&Num, &*Ptr);
}
