// Program: NodeInsert.C 
// Description: ����������

#include "list.h"

int NodeInsert( LinkList head, int n, int x )// �����½��
{
	LinkList s, p, q;
	s = ( LinkList )malloc( NodeSize ); // �����½��
	s->data = x;                        // �½��������ֵ
	p = head->next;                     // ��ͷ��ʼ
	q = head; 
	while( p != NULL )            // ����n��ǰһ���q
		if( p->data != n  )
			q = p, p = p->next;
		else
			break;
	if( p == NULL  )
			return 0;					// error:�Ҳ���p���
	s->next = p;                        // p����s��
	q->next = s;                        // q����sǰ
	return 1;							// �������
}

