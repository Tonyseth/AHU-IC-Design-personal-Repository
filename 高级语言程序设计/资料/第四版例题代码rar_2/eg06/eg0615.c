// Program: EG0615.c
#include <stdio.h>

////////////////////////////////////////////////////////////////////
// Function:    char *fun( char *str )
// Description: �����ַ���˳��
// Input:       char *str��ָ���ַ������ַ���ָ��
// Output:      ����ָ������õ��ַ������ַ���ָ��
////////////////////////////////////////////////////////////////////
char *fun( char *str )
{
    char i, j, len, tmp;    
		
	for( len = 0; str[len]; ++ len);
	
    for( i = 0; i < len; ++ i )
    {
		if( '0' <= str[i] && str[i] <= '9' )
		{
			tmp = str[i];
			for( j = i; str[j]; ++ j )
				str[j] = str[j+1];
			str[j-1] = tmp;
			i --;
			len --;
		}
    }
    return str;
}

void main( void )
{
    char str[80];
	
	gets(str);

    printf("%s\n", fun( str ));
}