// Program: EG0504.c 
// Description: ����ָ�����һά���顣 
#include <stdio.h> 
void main( void )               	
{
	int Num[]={2, 4, 6, 8, 10};
	short i=0, *Ptr=Num;

	printf("Num=%X Ptr=%X\n", Num, Ptr); 
	while( i < 5 )
	{
		printf("&Ptr[%d]=%X Ptr[%d]=%d\n",
			i, &Ptr[i], i, Ptr[i]); 
		i ++;
	}

}

