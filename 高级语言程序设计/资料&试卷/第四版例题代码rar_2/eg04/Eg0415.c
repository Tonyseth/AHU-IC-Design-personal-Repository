// Program: EG0415.C 
// Description: ��һ�������Сд��ĸ�����ַ������ܡ�
#include <stdio.h>
void main( void )
{
	char Str1[20], Str2[20];
	unsigned int i;

	printf("����һ������:");
	scanf("%s", Str1);

	i = 0;
	while( Str1[i] != '\0' )
	{
		Str2[i] = 'z' - Str1[i] + 'a';
		i ++;
	}
	Str2[i] = '\0';

	printf("The changed string is %s\n", Str2);
}
