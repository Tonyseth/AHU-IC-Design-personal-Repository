// File: list.h
#include <stdlib.h>
struct list
{
	int data;//数据域
	struct list *next;//指针域
};
typedef struct list LinkNode;
typedef struct list *LinkList;
#define NodeSize sizeof( LinkNode )

LinkList CreateList( int n );//创建n个结点的带头结点单链表
void VisitList( LinkList head );//遍历单链表
void NodeDelete( LinkList head, int n );//删除结点
int NodeInsert( LinkList head, int n, int x );// 插入结点