/* Program: EG0202.c 					    */
/* Description: ������Ĵ�д��ĸת��ΪСд��ĸ.  	    */

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
