// File: list.h
#include <stdlib.h>
struct list
{
	int data;//������
	struct list *next;//ָ����
};
typedef struct list LinkNode;
typedef struct list *LinkList;
#define NodeSize sizeof( LinkNode )

LinkList CreateList( int n );//����n�����Ĵ�ͷ��㵥����
void VisitList( LinkList head );//����������
void NodeDelete( LinkList head, int n );//ɾ�����
int NodeInsert( LinkList head, int n, int x );// ������