#include <stdio.h>
void main( void )
{
     float a;

     /****ERROR****/
     scanf("%d", a);//scanf("%f", &a);����ʱ������ǰҪ��&������������ǰ��Ҫ����һ��

     /******ERROR******/
     printf("a=%f\n, a)//printf("a=%f\n", a); �����ʽ�ַ���ǰ��Ҫ�Ӷ����",����Ҫ�ӽ�����;

	 
	
}