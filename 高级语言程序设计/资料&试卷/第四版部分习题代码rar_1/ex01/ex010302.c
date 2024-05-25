#include <stdio.h>
void main( void )
{
     float a;

     /****ERROR****/
     scanf("%d", a);//scanf("%f", &a);输入时变量名前要加&，变量的类型前后要保持一致

     /******ERROR******/
     printf("a=%f\n, a)//printf("a=%f\n", a); 输出格式字符串前后要加定界符",语句后要加结束符;

	 
	
}