// Program: EG0511.c 					    
// Description: ����ָ�뽫����Num�е�Ԫ�������š�
#include <stdio.h> 
#include <string.h>
void main( void )               	
{
	char Str[]="testString", *pBegin, *pEnd, tmp;

	printf("��תǰStr=%s\n", Str);

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
	
	printf("��ת��Str=%s\n", Str);
}
