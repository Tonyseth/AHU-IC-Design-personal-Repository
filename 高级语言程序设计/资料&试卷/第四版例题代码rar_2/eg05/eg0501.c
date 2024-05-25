// Program: EG05-01.c 					    
// Description: 演示变量与地址 
#include <stdio.h> 
void main( void )               	
{
	char Num[3][5]={"1234", "5678", "ABCD"};
	char ch1=0x21, ch2=0x31;
 	//char *ptr;     		
	
	printf("ch1=%x in %p\n", ch1, &ch1);  
 	printf("ch2=%x in %p\n", ch2, &ch2);  
	
	//ptr = & ch1; 
	//printf("ch1=%x in %x\n", *ptr, ptr);	
 //	ptr = & ch2;
 //	printf("ch2=%x in %x\n", *ptr, ptr);
}
