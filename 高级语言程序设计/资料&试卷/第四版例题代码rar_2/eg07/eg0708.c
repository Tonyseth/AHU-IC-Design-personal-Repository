// Program: EG0708.C 
// Description: ������Ĵ���������ʾ��

#include "list.h"

void main( void )
{
	LinkList head;

	head = CreateList( 5 );		// ������Ĵ���
	NodeDelete( head, 2303 );	// ɾ�����
	VisitList( head );          // ����������
}




