////////////////////////////////////////////////////////////////////////////////////
//��File name:			LXHAPI.c
//��Author:				Li Xin Hua.
//  Email:              lixinhua@ahu.edu.cn
//��Version:������������1.0
//��Date:				2022.06.22
//��Description:		This is a simple API for C programming:  
//����1. ChooseMenu:	Return a number from the menuitem you choose
//����2. ColorPrint:    Print some text using the specified foreground color and 
//����					background color at the specified position
//����...
//	  And it is a free product. 
//	  If you find it useful and want to update it, just let me know!
////////////////////////////////////////////////////////////////////////////////////

#include "LXHAPI.H"

////////////////////////////////////////////////////////////////////////////////////
//��Function:	 ChooseMenu()
//��Description: ��ʾmenu�����ɲ˵��ͨ�����¹���ѡ�񣬻س���ȷ�ϣ�����ѡ��
//��Input:		 char *menu[]���洢���ɲ˵�������
//��Output:		 ����һ������ѡ�������
//��Others:		 �˵�����������ģʽʵ�֣���ͨ�˵���Ϊ�ڵװ��֣���ǰ�˵���Ϊ�ڵװ���
////////////////////////////////////////////////////////////////////////////////////
int ChooseMenu( char *menu[] )
{
	int i=0, item=0, mrow=10, mcol=29, c, color;
	color = BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE ;

	clrscr();
	Frame( 20,  5,	50, 10 + MaxItem * 2, FOREGROUND_GREEN, color );
	ColorPrint( 7, 30, FOREGROUND_RED, BACKGROUND_BLUE, " ��  ��  �� ");
	//��Win10���Ʊ����Ӣ���ַ��ȿ��Ʊ��������ӱ�
	ColorPrint( 8, 25, FOREGROUND_RED, BACKGROUND_BLUE, "��������������������������������������������");
	//Win7��
	//ColorPrint( 8, 25, FOREGROUND_RED, BACKGROUND_BLUE, "����������������������");

	while( i < MaxItem )
	{
		ColorPrint( mrow + i * 2, mcol, FOREGROUND_RED, BACKGROUND_BLUE, menu[i] );
		i ++;
	}
	color = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED ;
	item = i;  i = 0;
	ColorPrint( mrow, mcol, FOREGROUND_BLUE, color, menu[i] );
	while(1)
	{
		c = getch(); //ColorPrint( 7, 30, FOREGROUND_RED, BACKGROUND_BLUE, ""); printf("%d %c", c, c);

		if( c == '0' || c == ESC || i == MaxItem-1 && c == ENTER )
		{
			clrscr();
			return 0;
		}

		if( c >= '0' && c < '0' + MaxItem )
		{
			clrscr();
			return c - '0';
		}

		switch( c )
		{
		case ENTER:
			clrscr();
			return i + 1;
		case UP:
			if( i > 0)
			{
				ColorPrint( mrow + i * 2, mcol, FOREGROUND_RED, BACKGROUND_BLUE, menu[i] );
				-- i;				
				ColorPrint( mrow + i * 2, mcol, FOREGROUND_BLUE, color, menu[i] );
			}
			break;
		case DOWN:
			if(i<item-1)
			{
				ColorPrint( mrow + i * 2, mcol, FOREGROUND_RED, BACKGROUND_BLUE, menu[i] );
				++ i;				
				ColorPrint( mrow + i * 2, mcol, FOREGROUND_BLUE, color, menu[i] );
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////
//��Function:	 clrscr()
//��Description: �����д�������������ɫΪ������ɫ
//��Input:		 ��
//��Output:		 ��
////////////////////////////////////////////////////////////////////////////////////
void clrscr( void )
{
	system("cls");     
	system("color 3F"); //3 ����ɫ  F ����ɫ
}

////////////////////////////////////////////////////////////////////////////////////
//��Function:	 ColorPrint()
//��Description: �������д���ָ����λ����ָ����ǰ��ɫ������ɫ��ʾһ������
//��Input:		 int row, int col��ָ�����кš��к�
//��			 int FgCcolor, int BkColor��ָ����ǰ��ɫ������ɫ
//��			 char *info������ʾ������
//��Output:		 ��
////////////////////////////////////////////////////////////////////////////////////
void ColorPrint( int row, int col, int FgColor, int BkColor, char *info )
{
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), FOREGROUND_INTENSITY | FgColor | BkColor );//���ø���ǰ��ɫ������ɫ

	GotoXY( row, col );

	printf( info );
}

////////////////////////////////////////////////////////////////////////////////////
//��Function:	 Frame()
//��Description: �������д���ָ����λ����ָ����ǰ��ɫ������ɫ����
//��Input:		 int LeftUpperX,  int LeftUpperY��ָ���������Ͻǵ��кš��к�
//��			 int RightLowerX, int RightLowerY��ָ���������½ǵ��кš��к�
//��			 int FgCcolor, int BkColor��ָ����ǰ��ɫ������ɫ
//��Output:		 ��
////////////////////////////////////////////////////////////////////////////////////
void Frame( int LeftUpperX,  int LeftUpperY,
	int RightLowerX, int RightLowerY,
	int FgColor, int BkColor )
{
	int i;
	char *LeftUp="��", *LeftLower="��", *RightUp="��", *RightLower="��";
	char *Horizonbar="��", *VertBar="��";


	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FgColor | BkColor );//���ø���ǰ��ɫ������ɫ

	//"���Ʃ���������
	GotoXY( LeftUpperY, LeftUpperX ); 
	printf( LeftUp );
	//Win10��
	for( i= LeftUpperX + 1; i < RightLowerX; i += 1 )
	//Win7��
	//for( i= LeftUpperX + 2; i < RightLowerX; i += 2 )
		printf( Horizonbar );
	printf( RightUp );

	//"���Ʃ�      ��
	for( i = LeftUpperY + 1; i <= RightLowerY; i ++ )
	{
		GotoXY( i, LeftUpperX );
		printf( VertBar ); 
		GotoXY( i, RightLowerX ); 
		printf( VertBar );
	}

	//"���Ʃ���������
	GotoXY( RightLowerY,  LeftUpperX ); 
	printf( LeftLower );
	//Win10��
	for( i= LeftUpperX + 1; i < RightLowerX; i += 1 )
	//Win7��
	//for( i= LeftUpperX + 2; i < RightLowerX; i += 2 )
		printf( Horizonbar );
	printf( RightLower );

}

////////////////////////////////////////////////////////////////////////////////////
//��Function:	 GotoXY()
//��Description: �ƶ���굽�����д���ָ����λ��
//��Input:		 int row, int col��ָ�����кš��к�
//��Output:		 ��
////////////////////////////////////////////////////////////////////////////////////
void GotoXY( int row, int col )          // ����ƶ����� 
{     
	COORD pos; 

	pos.X = col;     
	pos.Y = row;  

	SetConsoleCursorPosition ( GetStdHandle( STD_OUTPUT_HANDLE ), pos); 
}

////////////////////////////////////////////////////////////////////////////////////
//��Function:	 Wait()
//��Description: �������д�����ʾPress any key ......�������������
//��Input:		 ��
//��Output:		 ��
////////////////////////////////////////////////////////////////////////////////////
void Wait( void )
{
	printf("\nPress any key ......");
	getch();
}

////////////////////////////////////////////////////////////////////////////////////
//��Function:	 PlayMusic()
//��Description: ѭ�����ű�������music.mp3
//��Input:		 ��
//��Output:		 ��
//  Others:      �ܶ�VC++������ʹ��ʱĬ�ϵ���Unicode���뷽ʽ��
//��			 ANSI���뷽ʽ����Ҫ�ں�������Ӹ�A��mciSendString+A=mciSendStringA
//��			 �����ڶ������ʱ��char*��ΪWCHAR*
////////////////////////////////////////////////////////////////////////////////////
void PlayMusic( void )
{
	// ���ر������֣�music.mp3��������music
	mciSendStringA( "open music.mp3 alias music", NULL, NULL, NULL );

	// ѭ�����ţ�music
	mciSendStringA( "play music repeat", NULL, NULL, NULL );
}

////////////////////////////////////////////////////////////////////////////////////
//��Function:	 PlayRight()
//��Description: �������֣�right.wav
//��Input:		 ��
//��Output:		 ��
////////////////////////////////////////////////////////////////////////////////////
void PlayRight( void )
{
	mciSendStringA( "open right.wav alias right", NULL, NULL, NULL ); // ����right.wav

	mciSendStringA( "play right", NULL, NULL, NULL ); // ����right
	Sleep(2000); // �ȴ�right���Ž���

	mciSendStringA( "close right", NULL, NULL, NULL ); // �ر�right
}

////////////////////////////////////////////////////////////////////////////////////
//��Function:	 PlayWrong()
//��Description: �������֣�wrong.wav
//��Input:		 ��
//��Output:		 ��
////////////////////////////////////////////////////////////////////////////////////
void PlayWrong( void )
{
	mciSendStringA( "open wrong.wav alias wrong", NULL, NULL, NULL ); // ����wrong.wav

	mciSendStringA( "play wrong", NULL, NULL, NULL ); // ����wrong
	Sleep(1280); // �ȴ�wrong���Ž���

	mciSendStringA( "close wrong", NULL, NULL, NULL ); // �ر�wrong
}

////////////////////////////////////////////////////////////////////////////////////
//��Function:	 CloseMusic()
//��Description: �ر����֣�music
//��Input:		 ��
//��Output:		 ��
////////////////////////////////////////////////////////////////////////////////////
void CloseMusic( void )
{
	mciSendStringA( "close music", NULL, NULL, NULL ); // �ر�music.mp3
}
