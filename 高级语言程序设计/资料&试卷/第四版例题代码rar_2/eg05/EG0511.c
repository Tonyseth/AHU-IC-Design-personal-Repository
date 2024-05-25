// Program: EG0511.c 					    
// Description: 利用指针将数组Num中的元素逆序存放。
#include <stdio.h> 
#include <string.h>
void main( void )               	
{
	char Str[]="testString", *pBegin, *pEnd, tmp;

	printf("翻转前Str=%s\n", Str);

	pBegin = pEnd = Str; 
	while( *pEnd != '\0' )
		pEnd ++;
	-- pEnd;
	while( pBegin < pEnd )
	{
		tmp = *pBegin;
		*pBegin = *pEnd; 
		*pEnd = tmp; 
		++ pBegin;
		-- pEnd;
	}
	
	printf("翻转后Str=%s\n", Str);
}
