// Program: EG0616.c 
// Description: 编写指针函数将指定的十进制数转换为十六进制
#include <stdio.h>
#include <string.h>

////////////////////////////////////////////////////////////////////
// Function:    void reverse( char *Begin, char *End )
// Description: 递归翻转字符串
// Input:       char *Begin, char *End：指向字符串首尾字符的指针
// Output:      无
////////////////////////////////////////////////////////////////////
void reverse( char *Begin, char *End )
{
    char tmp;

    if( Begin < End )
	{
        tmp = *Begin;
		*Begin = *End;
		*End = tmp;
		reverse( ++ Begin, -- End );
	}
}

////////////////////////////////////////////////////////////////////
// Function:    char *itoh(unsigned int Num)
// Description: 将指定的整数转换为十六进制字符串
// Input:       unsigned int Num：待转换的整数
// Output:      返回十六进制字符串首字符的地址
////////////////////////////////////////////////////////////////////
char *itoh(unsigned int Num)
{
    int Hex,i=0;
	char HexNum[10];

	do
	{
		Hex = Num % 16;
		HexNum[i++] = ( Hex <= 9 ) ? Hex + '0' : Hex - 10 + 'a';
	}while( Num /= 16 );
	reverse( HexNum, HexNum + strlen( HexNum ) - 1 );

    return HexNum;
}
void main( void )
{
    printf("Hex(%d)=%s\n", 522, itoh( 522 ));
}