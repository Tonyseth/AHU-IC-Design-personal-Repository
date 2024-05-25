// Program: NodeInsert.C 
// Description: 遍历单链表

#include "list.h"

int NodeInsert( LinkList head, int n, int x )// 插入新结点
{
	LinkList s, p, q;
	s = ( LinkList )malloc( NodeSize ); // 创建新结点
	s->data = x;                        // 新结点数据域赋值
	p = head->next;                     // 从头开始
	q = head; 
	while( p != NULL )            // 查找n的前一结点q
		if( p->data != n  )
			q = p, p = p->next;
		else
			break;
	if( p == NULL  )
			return 0;					// error:找不到p结点
	s->next = p;                        // p排在s后
	q->next = s;                        // q排在s前
	return 1;							// 插入完毕
}

