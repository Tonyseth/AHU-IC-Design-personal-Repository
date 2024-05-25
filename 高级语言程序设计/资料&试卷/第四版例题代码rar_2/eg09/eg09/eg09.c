////////////////////////////////////////////////////////////////////////////////////
//��Program:			eg09.c
//��Author:				Li Xin Hua.
//��Description:		����LXHAPI��Ʋ˵�ʾ��  
////////////////////////////////////////////////////////////////////////////////////

#include "lxhapi.h"

////////////////////////////////////////////////////////////////////// 
//��Function:	 InitMenu()
//��Description: ����menu�Ĳ˵�������
//��Input:		 char *menu[]��menu�����ɲ˵�������
//��Output:		 ��
////////////////////////////////////////////////////////////////////// 
void InitMenu( char *menu[] )
{
	menu[0]=" 1.��1�������� ";
	menu[1]=" 2.��2�������� ";
	menu[2]=" 3.��3�������� ";
	menu[3]=" 0. Quit      ";
}

void sub1( void )
{
	int Sol;

	ColorPrint( 8, 12, FOREGROUND_RED, BACKGROUND_BLUE, "1. ((10*(6-3))-6)=?" );
	scanf("%d", &Sol);

	if( Sol == 24 )
		PlayRight();
	else
		PlayWrong();

	Wait( );
}

void sub2( void )
{
	int Sol;	

	ColorPrint( 8, 12, FOREGROUND_RED, BACKGROUND_BLUE, "2. 5��(5-1/5)=?" );
	scanf("%d", &Sol)
		;
	if( Sol == 24 )
		PlayRight();
	else
		PlayWrong();

	Wait( );
}

void sub3( void )
{
	int Sol;	

	ColorPrint( 8, 12, FOREGROUND_RED, BACKGROUND_BLUE, "3. (3+3/7)*7=?" );
	scanf("%d", &Sol)
		;
	if( Sol == 24 )
		PlayRight();
	else
		PlayWrong();

	Wait( );
}

void main( void )
{
	char *menu[MaxItem];
	int done=1;

	clrscr();
	InitMenu( menu );
	PlayMusic();

	do
	{
		switch( ChooseMenu( menu ) )
		{
		case 1:
			sub1();
			break;
		case 2:
			sub2();
			break;
		case 3:
			sub3();
			break;
		default :
			done=0;
		}
	}while( done );

	CloseMusic();
}
