// Program: EG0613.c
// Description: �ݹ鷨�����ַ�������
#include <stdio.h>

////////////////////////////////////////////////////////////
// Function:    int strlen( char *str )
// Description: �ݹ鷨���ַ�������
// Input:        str��ָ���ַ������ַ���ָ��
// Output:       �����ַ�������
////////////////////////////////////////////////////////////
int strlen( char *str )
{
    if( *str == NULL )
        return 0;
    else
        return strlen( ++ str ) + 1;
}
void main( void )
{
    char str[20];

    printf("������1���ַ���:");
    gets( str );

    printf("\"%s\"����Ϊ%d\n",  str, strlen( str )); 
}

