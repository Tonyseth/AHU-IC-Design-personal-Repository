// Program: EG0709.C 
// Description: ������Ĳ���ʾ��

#include <stdio.h>
#include "list.h"

void main( void )
{
	LinkList head;

	head = CreateList( 0 );					// ������Ĵ���
	if( NodeInsert( head, 2403, 2406 ) )	// ������
		VisitList( head );					// ����������
	else
		printf("The node not found!\n");
}




