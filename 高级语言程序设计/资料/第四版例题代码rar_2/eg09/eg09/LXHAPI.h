////////////////////////////////////////////////////////////////////////////////////
//　File name:			LXHAPI.H
//　Author:				Li Xin Hua.
//  Email:              lixinhua@ahu.edu.cn
//　Version:　　　　　　1.0
//　Date:				2022.06.22
//　Description:		This is a simple API for C programming:  
//　　1. ChooseMenu:	Return a number from the menuitem you choose
//　　2. ColorPrint:    Print some text using the specified foreground color and background color at the specified position
//　　...
//	  And it is a free product. 
//	  If you find it useful and want to update it, just let me know!
////////////////////////////////////////////////////////////////////////////////////
#include <conio.h>    // 使用 getch() system();  函数
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>  // 使用 SetConsoleTextAttribute() GetStdHandle() SetConsoleCursorPosition()函数
#pragma comment(lib,"Winmm.lib")

// 菜单选项数目
#define MaxItem 4

// 常见按键键值
#define ESC   27
#define ENTER 13
#define UP    72
#define DOWN  80
#define LEFT  75
#define RIGHT 77

////////////////////////////////////////////////////////////////////////////////////
//　Function:	 ChooseMenu()
//　Description: 显示menu的若干菜单项，通过上下光标键选择，回车键确认，返回选项
//　Input:		 char *menu[]：存储若干菜单项文字
//　Output:		 返回一个代表选项的整数
//　Others:		 菜单基于命令行模式实现，普通菜单项为蓝底红字，当前菜单项为白底蓝字
////////////////////////////////////////////////////////////////////////////////////
int ChooseMenu( char *menu[] );

////////////////////////////////////////////////////////////////////////////////////
//　Function:	 clrscr()
//　Description: 命令行窗口清屏，背景色为黑底
//　Input:		 无
//　Output:		 无
////////////////////////////////////////////////////////////////////////////////////
void clrscr( void );

////////////////////////////////////////////////////////////////////////////////////
//　Function:	 ColorPrint()
//　Description: 在命令行窗口指定的位置用指定的前景色、背景色显示一段文字
//　Input:		 int row, int col：指定的行号、列号
//　			 int FgCcolor, int BkColor：指定的前景色、背景色
//　			 char *info：需显示的文字
//　Output:		 无
//　Others:		 设置颜色的参数低四位控制前景色，高四位控制背景色，可叠加:
//				 FOREGROUND_BLUE	    //字体颜色:蓝	1
//				 FOREGROUND_GREEN	    //字体颜色:绿	2
//				 FOREGROUND_RED		    //字体颜色:红	4
//				 FOREGROUND_INTENSITY   //前景色高亮	8
//				 BACKGROUND_BLUE	    //背景颜色:蓝	16
//				 BACKGROUND_GREEN	    //背景颜色:绿	32
//				 BACKGROUND_RED	        //背景颜色:红	64
//				 BACKGROUND_INTENSITY   //背景色高亮	128
////////////////////////////////////////////////////////////////////////////////////
void ColorPrint( int row, int col, int FgColor, int BkColor, char *info );
 
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
            int FgColor, int BkColor );

////////////////////////////////////////////////////////////////////////////////////
//　Function:	 GotoXY()
//　Description: 移动光标到命令行窗口指定的位置
//　Input:		 int row, int col：指定的行号、列号
//　Output:		 无
////////////////////////////////////////////////////////////////////////////////////
void GotoXY( int row, int col );


////////////////////////////////////////////////////////////////////////////////////
//　Function:	 PlayMusic()
//　Description: 循环播放指定音乐
//　Input:		 无
//　Output:		 无
////////////////////////////////////////////////////////////////////////////////////
void PlayMusic( void );

////////////////////////////////////////////////////////////////////////////////////
//　Function:	 Wait()
//　Description: 在命令行窗口显示Press any key ......，按任意键继续
//　Input:		 无
//　Output:		 无
////////////////////////////////////////////////////////////////////////////////////
void Wait( void );

////////////////////////////////////////////////////////////////////////////////////
//　Function:	 PlayMusic()
//　Description: 循环播放背景音乐music.mp3
//　Input:		 无
//　Output:		 无
//  Others:      很多VC++函数在使用时默认调用Unicode编码方式。
//　			 ANSI编码方式调用要在函数后面加个A：mciSendString+A=mciSendStringA
//　			 或者在定义参数时把char*改为WCHAR*
////////////////////////////////////////////////////////////////////////////////////
void PlayMusic( void );

////////////////////////////////////////////////////////////////////////////////////
//　Function:	 PlayRight()
//　Description: 播放音乐：right
//　Input:		 无
//　Output:		 无
////////////////////////////////////////////////////////////////////////////////////
void PlayRight( void );

////////////////////////////////////////////////////////////////////////////////////
//　Function:	 PlayWrong()
//　Description: 播放音乐：wrong
//　Input:		 无
//　Output:		 无
////////////////////////////////////////////////////////////////////////////////////
void PlayWrong( void );

////////////////////////////////////////////////////////////////////////////////////
//　Function:	 CloseMusic()
//　Description: 关闭各种音乐
//　Input:		 无
//　Output:		 无
////////////////////////////////////////////////////////////////////////////////////
void CloseMusic( void );
