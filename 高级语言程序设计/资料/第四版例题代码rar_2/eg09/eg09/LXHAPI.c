////////////////////////////////////////////////////////////////////////////////////
//　File name:			LXHAPI.c
//　Author:				Li Xin Hua.
//  Email:              lixinhua@ahu.edu.cn
//　Version:　　　　　　1.0
//　Date:				2022.06.22
//　Description:		This is a simple API for C programming:  
//　　1. ChooseMenu:	Return a number from the menuitem you choose
//　　2. ColorPrint:    Print some text using the specified foreground color and 
//　　					background color at the specified position
//　　...
//	  And it is a free product. 
//	  If you find it useful and want to update it, just let me know!
////////////////////////////////////////////////////////////////////////////////////

#include "LXHAPI.H"

////////////////////////////////////////////////////////////////////////////////////
//　Function:	 ChooseMenu()
//　Description: 显示menu的若干菜单项，通过上下光标键选择，回车键确认，返回选项
//　Input:		 char *menu[]：存储若干菜单项文字
//　Output:		 返回一个代表选项的整数
//　Others:		 菜单基于命令行模式实现，普通菜单项为黑底白字，当前菜单项为黑底白字
////////////////////////////////////////////////////////////////////////////////////
int ChooseMenu( char *menu[] )
{
	int i=0, item=0, mrow=10, mcol=29, c, color;
	color = BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE ;

	clrscr();
	Frame( 20,  5,	50, 10 + MaxItem * 2, FOREGROUND_GREEN, color );
	ColorPrint( 7, 30, FOREGROUND_RED, BACKGROUND_BLUE, " 主  菜  单 ");
	//　Win10：制表符与英文字符等宽，制表符长度需加倍
	ColorPrint( 8, 25, FOREGROUND_RED, BACKGROUND_BLUE, "──────────────────────");
	//Win7：
	//ColorPrint( 8, 25, FOREGROUND_RED, BACKGROUND_BLUE, "───────────");

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
//　Function:	 clrscr()
//　Description: 命令行窗口清屏，背景色为亮湖蓝色
//　Input:		 无
//　Output:		 无
////////////////////////////////////////////////////////////////////////////////////
void clrscr( void )
{
	system("cls");     
	system("color 3F"); //3 湖蓝色  F 亮白色
}

////////////////////////////////////////////////////////////////////////////////////
//　Function:	 ColorPrint()
//　Description: 在命令行窗口指定的位置用指定的前景色、背景色显示一段文字
//　Input:		 int row, int col：指定的行号、列号
//　			 int FgCcolor, int BkColor：指定的前景色、背景色
//　			 char *info：需显示的文字
//　Output:		 无
////////////////////////////////////////////////////////////////////////////////////
void ColorPrint( int row, int col, int FgColor, int BkColor, char *info )
{
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), FOREGROUND_INTENSITY | FgColor | BkColor );//设置高亮前景色、背景色

	GotoXY( row, col );

	printf( info );
}

////////////////////////////////////////////////////////////////////////////////////
//　Function:	 Frame()
//　Description: 在命令行窗口指定的位置用指定的前景色、背景色画框
//　Input:		 int LeftUpperX,  int LeftUpperY：指定区域左上角的行号、列号
//　			 int RightLowerX, int RightLowerY：指定区域右下角的行号、列号
//　			 int FgCcolor, int BkColor：指定的前景色、背景色
//　Output:		 无
////////////////////////////////////////////////////////////////////////////////////
void Frame( int LeftUpperX,  int LeftUpperY,
	int RightLowerX, int RightLowerY,
	int FgColor, int BkColor )
{
	int i;
	char *LeftUp="┏", *LeftLower="┗", *RightUp="┓", *RightLower="┛";
	char *Horizonbar="━", *VertBar="┃";


	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FgColor | BkColor );//设置高亮前景色、背景色

	//"绘制┏━━━┓
	GotoXY( LeftUpperY, LeftUpperX ); 
	printf( LeftUp );
	//Win10：
	for( i= LeftUpperX + 1; i < RightLowerX; i += 1 )
	//Win7：
	//for( i= LeftUpperX + 2; i < RightLowerX; i += 2 )
		printf( Horizonbar );
	printf( RightUp );

	//"绘制┃      ┃
	for( i = LeftUpperY + 1; i <= RightLowerY; i ++ )
	{
		GotoXY( i, LeftUpperX );
		printf( VertBar ); 
		GotoXY( i, RightLowerX ); 
		printf( VertBar );
	}

	//"绘制┗━━━┛
	GotoXY( RightLowerY,  LeftUpperX ); 
	printf( LeftLower );
	//Win10：
	for( i= LeftUpperX + 1; i < RightLowerX; i += 1 )
	//Win7：
	//for( i= LeftUpperX + 2; i < RightLowerX; i += 2 )
		printf( Horizonbar );
	printf( RightLower );

}

////////////////////////////////////////////////////////////////////////////////////
//　Function:	 GotoXY()
//　Description: 移动光标到命令行窗口指定的位置
//　Input:		 int row, int col：指定的行号、列号
//　Output:		 无
////////////////////////////////////////////////////////////////////////////////////
void GotoXY( int row, int col )          // 光标移动函数 
{     
	COORD pos; 

	pos.X = col;     
	pos.Y = row;  

	SetConsoleCursorPosition ( GetStdHandle( STD_OUTPUT_HANDLE ), pos); 
}

////////////////////////////////////////////////////////////////////////////////////
//　Function:	 Wait()
//　Description: 在命令行窗口显示Press any key ......，按任意键继续
//　Input:		 无
//　Output:		 无
////////////////////////////////////////////////////////////////////////////////////
void Wait( void )
{
	printf("\nPress any key ......");
	getch();
}

////////////////////////////////////////////////////////////////////////////////////
//　Function:	 PlayMusic()
//　Description: 循环播放背景音乐music.mp3
//　Input:		 无
//　Output:		 无
//  Others:      很多VC++函数在使用时默认调用Unicode编码方式。
//　			 ANSI编码方式调用要在函数后面加个A：mciSendString+A=mciSendStringA
//　			 或者在定义参数时把char*改为WCHAR*
////////////////////////////////////////////////////////////////////////////////////
void PlayMusic( void )
{
	// 加载背景音乐：music.mp3，别名：music
	mciSendStringA( "open music.mp3 alias music", NULL, NULL, NULL );

	// 循环播放：music
	mciSendStringA( "play music repeat", NULL, NULL, NULL );
}

////////////////////////////////////////////////////////////////////////////////////
//　Function:	 PlayRight()
//　Description: 播放音乐：right.wav
//　Input:		 无
//　Output:		 无
////////////////////////////////////////////////////////////////////////////////////
void PlayRight( void )
{
	mciSendStringA( "open right.wav alias right", NULL, NULL, NULL ); // 加载right.wav

	mciSendStringA( "play right", NULL, NULL, NULL ); // 播放right
	Sleep(2000); // 等待right播放结束

	mciSendStringA( "close right", NULL, NULL, NULL ); // 关闭right
}

////////////////////////////////////////////////////////////////////////////////////
//　Function:	 PlayWrong()
//　Description: 播放音乐：wrong.wav
//　Input:		 无
//　Output:		 无
////////////////////////////////////////////////////////////////////////////////////
void PlayWrong( void )
{
	mciSendStringA( "open wrong.wav alias wrong", NULL, NULL, NULL ); // 加载wrong.wav

	mciSendStringA( "play wrong", NULL, NULL, NULL ); // 播放wrong
	Sleep(1280); // 等待wrong播放结束

	mciSendStringA( "close wrong", NULL, NULL, NULL ); // 关闭wrong
}

////////////////////////////////////////////////////////////////////////////////////
//　Function:	 CloseMusic()
//　Description: 关闭音乐：music
//　Input:		 无
//　Output:		 无
////////////////////////////////////////////////////////////////////////////////////
void CloseMusic( void )
{
	mciSendStringA( "close music", NULL, NULL, NULL ); // 关闭music.mp3
}
