// Program: VisitList.C 
// Description: ����������

#include <stdio.h>
#include "list.h"

void VisitList( LinkList head )		// ����������
{
	LinkList p;                     // ������ָ��p
	p = head->next;                 // pָ���һ�����
	while( p != NULL )              // ѭ���������ң�ֱ��pΪ��
	{ 
		printf("%d ", p->data);     // ���ÿ���������
		p = p->next;                // pָ����һ�����
	}
	printf("\n");
}

