// Program: CreateList.C 
// Description: ������Ĵ���

#include "list.h"

LinkList CreateList( int n )                // ����һ��n�����Ĵ�ͷ���ĵ�����
{
	LinkList head, p, q;                  	// ����3�����ָ��
	int i;

	head = p = ( LinkList )malloc( NodeSize );	// ����ͷ���
	p -> next = 0;                         // ��β�ÿ� 
	for( i = 0 ; i < n; i ++ )             // ѭ������n����㵥����
	{ 
		q = (LinkList)malloc( NodeSize );	// �����½��
		printf("input data:");
		scanf("%d", &q->data);   	      	// ����������
		p->next = q;   	             	// ��������β��
		q->next = NULL;                  	// �±�β�ÿ�
		p = q;                            // pָ���½�㣬׼����һ������
	}

	return head;                  	      	// ����ָ��ͷ����ָ��
}

