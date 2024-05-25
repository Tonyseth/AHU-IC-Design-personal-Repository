/* Program: EG0202.c 					    */
/* Description: 将输入的大写字母转换为小写字母.  	    */

#include <stdio.h>
//#include <conio.h>

void main (void)
{
	char c;
	
	c = getchar();
	c >= 'A' && c <= 'Z' ? putchar( c - 'A' + 'a' ): putchar( c );
	
 	//c=getch();
 	//putchar(c);
 	//c=getche();
 	//putchar(c);
}
