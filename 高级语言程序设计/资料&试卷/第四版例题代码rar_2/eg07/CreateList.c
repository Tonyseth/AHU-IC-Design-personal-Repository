// Program: CreateList.C 
// Description: 单链表的创建

#include "list.h"

LinkList CreateList( int n )                // 创建一个n个结点的带头结点的单链表
{
	LinkList head, p, q;                  	// 定义3个结点指针
	int i;

	head = p = ( LinkList )malloc( NodeSize );	// 创建头结点
	p -> next = 0;                         // 表尾置空 
	for( i = 0 ; i < n; i ++ )             // 循环建立n个结点单链表
	{ 
		q = (LinkList)malloc( NodeSize );	// 创建新结点
		printf("input data:");
		scanf("%d", &q->data);   	      	// 输入新数据
		p->next = q;   	             	// 加入链表尾部
		q->next = NULL;                  	// 新表尾置空
		p = q;                            // p指向新结点，准备下一次输入
	}

	return head;                  	      	// 返回指向头结点的指针
}

