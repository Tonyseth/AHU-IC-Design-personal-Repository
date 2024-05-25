// Program: EG0608.c
// Description: 自定义strcmp函数实现两个字符串的比较。

#include <stdio.h>

////////////////////////////////////////////////////////////
// Function:    int strcmp( char *str1, char *str2 )
// Description: 比较两个字符串
// Input:        char *str1, char *str2：两个指向两个字符串首字符的指针
// Output:       若两个字符串相等，则返回零；若字符串1大于字符串2，则返回大于零的数；
//                 否则，则返回小于零的数
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
