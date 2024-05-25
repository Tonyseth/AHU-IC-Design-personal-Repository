// Program: EG0608.c
// Description: �Զ���strcmp����ʵ�������ַ����ıȽϡ�

#include <stdio.h>

////////////////////////////////////////////////////////////
// Function:    int strcmp( char *str1, char *str2 )
// Description: �Ƚ������ַ���
// Input:        char *str1, char *str2������ָ�������ַ������ַ���ָ��
// Output:       �������ַ�����ȣ��򷵻��㣻���ַ���1�����ַ���2���򷵻ش����������
//                 �����򷵻�С�������
////////////////////////////////////////////////////////////
int strcmp( char *str1, char *str2 )
{
    while( *str1 && *str2 && *str1 == *str2 )
        str1 ++, str2 ++;

    return *str1 - *str2;
}
void main( void )
{
    char str1[80], str2[80];
	
    gets( str1 );
    gets( str2 );
    
    printf("strcmp(\"%s\",\"%s\")=%d\n", str1, str2, strcmp( str1, str2 ));
}
