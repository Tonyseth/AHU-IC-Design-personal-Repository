// Program: EG0614.c
// Description: 递归法求解Hanoi塔问题
#include <stdio.h>

////////////////////////////////////////////////////////////////////
// Function:    void move( int num, char one, char two, char three )
// Description: 递归法求解Hanoi塔
// Input:       int num：Hanoi塔圆盘数
//              char one, char two, char three：三根针名称
// Output:      无
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

