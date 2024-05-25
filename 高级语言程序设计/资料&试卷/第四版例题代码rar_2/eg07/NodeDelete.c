// Program: NodeDelete.C 
// Description: 单链表删除结点

#include <stdio.h>
#include "list.h"

void NodeDelete( LinkList head, int n )
{
    LinkList p=head->next, q;

    //p不是要删除的结点，也不是最后一个结点时循环
    while( p != NULL && p->data != n )
    {
        q = p;                   // q指向当前结点
        p = p->next;             // p指向下一结点
    }

    if( p != NULL &&  p->data == n )
    {
        q->next = p->next;    	// q指针域指向被删结点的下一结点
        free( p );             	// 删除结点
        printf("The node is deleted\n");
    }
    else
        printf("The node not found!\n"); // 找不到删除结点
}
