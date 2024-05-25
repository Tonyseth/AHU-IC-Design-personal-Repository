// Program: EG0703.C 
// Description: 模拟牌类游戏顺序发52张牌
#include <stdio.h>
typedef struct
{
    char point;        //点数
    char face;         //花色
}CARD;
void main( void )
{
    char *Face[4]={"红心", "方块", "梅花", "黑桃"};               //存储花色名称
    //char *Point[13]={"Ace","Deuce","Three","Four","Five","Six","Seven",
    //               "Eight","Nine","Ten","Jack","Queen","King"};//存储点数名称
	char *Point[13]={"A","2","3","4","5","6","7", "8","9","10","J","Q","K"};

    int card, i, j;
    CARD  Player[4][13];
    
    //顺序发牌
    for( card = 0; card < 52; card ++ )
    {
        i = card % 4;
        j = card / 4;
        Player[i][j].face = i;
        Player[i][j].point = j;
    } 
    
    //顺序显示四位玩家的牌面
    printf("Play1\t\tPLay2\t\tPLay3\t\tPLay4\n");
    for( j = 0; j < 13; j ++ )
    {
        for( i  =0; i < 4; i ++ )
            printf("%-2s%-6s\t", Face[Player[i][j].face],
                     Point[Player[i][j].point]);
        printf("\n");
    }
}



