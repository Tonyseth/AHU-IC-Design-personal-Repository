// Program: EG0614.c
// Description: �ݹ鷨���Hanoi������
#include <stdio.h>

////////////////////////////////////////////////////////////////////
// Function:    void move( int num, char one, char two, char three )
// Description: �ݹ鷨���Hanoi��
// Input:       int num��Hanoi��Բ����
//              char one, char two, char three������������
// Output:      ��
////////////////////////////////////////////////////////////////////
void move( int num, char one, char two, char three )
{
    if( num == 1 )
        printf("%c-->%c\n", one, three);
    else
    {
        move( num - 1, one, three, two );
        printf("%c-->%c\n", one, three);
        move( num - 1, two, one, three );
    }
}
void main( void )
{
    int Num=3;
    printf("Step to moving %d diskes:\n", Num);
    move( Num, 'A', 'B', 'C' );
}

