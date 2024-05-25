// Program: EG0616.c 
// Description: ��дָ�뺯����ָ����ʮ������ת��Ϊʮ������
#include <stdio.h>
#include <string.h>

////////////////////////////////////////////////////////////////////
// Function:    void reverse( char *Begin, char *End )
// Description: �ݹ鷭ת�ַ���
// Input:       char *Begin, char *End��ָ���ַ�����β�ַ���ָ��
// Output:      ��
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
// Description: ��ָ��������ת��Ϊʮ�������ַ���
// Input:       unsigned int Num����ת��������
// Output:      ����ʮ�������ַ������ַ��ĵ�ַ
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