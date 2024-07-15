// Program: EG0613.c
// Description: 递归法计算字符串长度
#include <stdio.h>

////////////////////////////////////////////////////////////
// Function:    int strlen( char *str )
// Description: 递归法求字符串长度
// Input:        str：指向字符串首字符的指针
// Output:       返回字符串长度
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

    printf("请输入1个字符串:");
    gets( str );

    printf("\"%s\"长度为%d\n",  str, strlen( str )); 
}

