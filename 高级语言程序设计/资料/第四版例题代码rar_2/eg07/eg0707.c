// Program: EG0707.C 
// Description: 单链表的创建、遍历示范

#include "list.h"

void main( void )
{
	LinkList head; 

	head = CreateList( 5 );		// 单链表的创建
	VisitList( head );        //遍历单链表
}




