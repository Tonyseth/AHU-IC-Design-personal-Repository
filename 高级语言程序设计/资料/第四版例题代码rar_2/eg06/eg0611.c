// Program: EG0610.c
// Description: 输入2个字符串，将二者连接后输出结果。
#include <stdio.h>
////////////////////////////////////////////////////////////
// Function:    int strlen( char str[] )
// Description: 求字符串长度
// Input:       str：指向字符串首字符的指针
// Output:      返回字符串长度
////////////////////////////////////////////////////////////
int strlen( char str[] )
{
    int i=0;

    while( str[i] != '\0' )
		++ i;

    return i;
}
////////////////////////////////////////////////////////////
// Function:    char *StrCat( char *ptr1, char *ptr2 )
// Description: 连接两个字符串
// Input:       char *ptr1, char *ptr2：两个指向两个字符串首字符的指针
// Output:      返回连接后字符串首字符地址
////////////////////////////////////////////////////////////
char *StrCat( char *ptr1, char *ptr2 )
{
    int len;

    len = strlen( ptr1 );
    ptr1 += len;
    len += strlen( ptr2 );
    while( *ptr1 = *ptr2 )
        ptr1 ++, ptr2 ++;

    return ptr1 - len;
}
void main( void )
{
    char str1[20], str2[20];

    printf("请输入2个字符串:\n");
    gets( str1 );
    gets( str2 );

    printf("新串：%s\n", StrCat( str1, str2 ));
}
