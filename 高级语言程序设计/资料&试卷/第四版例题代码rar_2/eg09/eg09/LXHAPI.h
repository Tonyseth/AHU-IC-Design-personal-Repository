////////////////////////////////////////////////////////////////////////////////////
//��File name:			LXHAPI.H
//��Author:				Li Xin Hua.
//  Email:              lixinhua@ahu.edu.cn
//��Version:������������1.0
//��Date:				2022.06.22
//��Description:		This is a simple API for C programming:  
//����1. ChooseMenu:	Return a number from the menuitem you choose
//����2. ColorPrint:    Print some text using the specified foreground color and background color at the specified position
//����...
//	  And it is a free product. 
//	  If you find it useful and want to update it, just let me know!
////////////////////////////////////////////////////////////////////////////////////
#include <conio.h>    // ʹ�� getch() system();  ����
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>  // ʹ�� SetConsoleTextAttribute() GetStdHandle() SetConsoleCursorPosition()����
#pragma comment(lib,"Winmm.lib")

// �˵�ѡ����Ŀ
#define MaxItem 4

// ����������ֵ
#define ESC   27
#define ENTER 13
#define UP    72
#define DOWN  80
#define LEFT  75
#define RIGHT 77

////////////////////////////////////////////////////////////////////////////////////
//��Function:	 ChooseMenu()
//��Description: ��ʾmenu�����ɲ˵��ͨ�����¹���ѡ�񣬻س���ȷ�ϣ�����ѡ��
//��Input:		 char *menu[]���洢���ɲ˵�������
//��Output:		 ����һ������ѡ�������
//��Others:		 �˵�����������ģʽʵ�֣���ͨ�˵���Ϊ���׺��֣���ǰ�˵���Ϊ�׵�����
////////////////////////////////////////////////////////////////////////////////////
int ChooseMenu( char *menu[] );

////////////////////////////////////////////////////////////////////////////////////
//��Function:	 clrscr()
//��Description: �����д�������������ɫΪ�ڵ�
//��Input:		 ��
//��Output:		 ��
////////////////////////////////////////////////////////////////////////////////////
void clrscr( void );

////////////////////////////////////////////////////////////////////////////////////
//��Function:	 ColorPrint()
//��Description: �������д���ָ����λ����ָ����ǰ��ɫ������ɫ��ʾһ������
//��Input:		 int row, int col��ָ�����кš��к�
//��			 int FgCcolor, int BkColor��ָ����ǰ��ɫ������ɫ
//��			 char *info������ʾ������
//��Output:		 ��
//��Others:		 ������ɫ�Ĳ�������λ����ǰ��ɫ������λ���Ʊ���ɫ���ɵ���:
//				 FOREGROUND_BLUE	    //������ɫ:��	1
//				 FOREGROUND_GREEN	    //������ɫ:��	2
//				 FOREGROUND_RED		    //������ɫ:��	4
//				 FOREGROUND_INTENSITY   //ǰ��ɫ����	8
//				 BACKGROUND_BLUE	    //������ɫ:��	16
//				 BACKGROUND_GREEN	    //������ɫ:��	32
//				 BACKGROUND_RED	        //������ɫ:��	64
//				 BACKGROUND_INTENSITY   //����ɫ����	128
////////////////////////////////////////////////////////////////////////////////////
void ColorPrint( int row, int col, int FgColor, int BkColor, char *info );
 
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
            int FgColor, int BkColor );

////////////////////////////////////////////////////////////////////////////////////
//��Function:	 GotoXY()
//��Description: �ƶ���굽�����д���ָ����λ��
//��Input:		 int row, int col��ָ�����кš��к�
//��Output:		 ��
////////////////////////////////////////////////////////////////////////////////////
void GotoXY( int row, int col );


////////////////////////////////////////////////////////////////////////////////////
//��Function:	 PlayMusic()
//��Description: ѭ������ָ������
//��Input:		 ��
//��Output:		 ��
////////////////////////////////////////////////////////////////////////////////////
void PlayMusic( void );

////////////////////////////////////////////////////////////////////////////////////
//��Function:	 Wait()
//��Description: �������д�����ʾPress any key ......�������������
//��Input:		 ��
//��Output:		 ��
////////////////////////////////////////////////////////////////////////////////////
void Wait( void );

////////////////////////////////////////////////////////////////////////////////////
//��Function:	 PlayMusic()
//��Description: ѭ�����ű�������music.mp3
//��Input:		 ��
//��Output:		 ��
//  Others:      �ܶ�VC++������ʹ��ʱĬ�ϵ���Unicode���뷽ʽ��
//��			 ANSI���뷽ʽ����Ҫ�ں�������Ӹ�A��mciSendString+A=mciSendStringA
//��			 �����ڶ������ʱ��char*��ΪWCHAR*
////////////////////////////////////////////////////////////////////////////////////
void PlayMusic( void );

////////////////////////////////////////////////////////////////////////////////////
//��Function:	 PlayRight()
//��Description: �������֣�right
//��Input:		 ��
//��Output:		 ��
////////////////////////////////////////////////////////////////////////////////////
void PlayRight( void );

////////////////////////////////////////////////////////////////////////////////////
//��Function:	 PlayWrong()
//��Description: �������֣�wrong
//��Input:		 ��
//��Output:		 ��
////////////////////////////////////////////////////////////////////////////////////
void PlayWrong( void );

////////////////////////////////////////////////////////////////////////////////////
//��Function:	 CloseMusic()
//��Description: �رո�������
//��Input:		 ��
//��Output:		 ��
////////////////////////////////////////////////////////////////////////////////////
void CloseMusic( void );
