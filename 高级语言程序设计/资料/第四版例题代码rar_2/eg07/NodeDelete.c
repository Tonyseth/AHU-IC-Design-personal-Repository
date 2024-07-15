// Program: NodeDelete.C 
// Description: ������ɾ�����

#include <stdio.h>
#include "list.h"

void NodeDelete( LinkList head, int n )
{
    LinkList p=head->next, q;

    //p����Ҫɾ���Ľ�㣬Ҳ�������һ�����ʱѭ��
    while( p != NULL && p->data != n )
    {
        q = p;                   // qָ��ǰ���
        p = p->next;             // pָ����һ���
    }

    if( p != NULL &&  p->data == n )
    {
        q->next = p->next;    	// qָ����ָ��ɾ������һ���
        free( p );             	// ɾ�����
        printf("The node is deleted\n");
    }
    else
        printf("The node not found!\n"); // �Ҳ���ɾ�����
}
