// Program: VisitList.C 
// Description: 遍历单链表

#include <stdio.h>
#include "list.h"

void VisitList( LinkList head )		// 遍历单链表
{
	LinkList p;                     // 定义结点指针p
	p = head->next;                 // p指向第一个结点
	while( p != NULL )              // 循环遍历查找，直到p为空
	{ 
		printf("%d ", p->data);     // 输出每个结点数据
		p = p->next;                // p指向下一个结点
	}
	printf("\n");
}

