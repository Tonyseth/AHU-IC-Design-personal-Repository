// Program: EG0709.C 
// Description: 单链表的插入示范

#include <stdio.h>
#include "list.h"

void main( void )
{
	LinkList head;

	head = CreateList( 0 );					// 单链表的创建
	if( NodeInsert( head, 2403, 2406 ) )	// 插入结点
		VisitList( head );					// 遍历单链表
	else
		printf("The node not found!\n");
}




