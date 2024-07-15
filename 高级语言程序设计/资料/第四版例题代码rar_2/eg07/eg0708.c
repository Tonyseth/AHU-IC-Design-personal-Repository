// Program: EG0708.C 
// Description: 单链表的创建、遍历示范

#include "list.h"

void main( void )
{
	LinkList head;

	head = CreateList( 5 );		// 单链表的创建
	NodeDelete( head, 2303 );	// 删除结点
	VisitList( head );          // 遍历单链表
}




