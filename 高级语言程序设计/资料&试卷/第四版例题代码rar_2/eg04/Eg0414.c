// Program: EG0412.C 
// Description: ���ÿ⺯������һ�������ʮ��������ת��Ϊ�����������ַ�����
#include <stdio.h>
void main( void )
{
    char Str[30], tmp;
    int Num, i, j, Sign; 
 
    printf("����һ������:");
	scanf("%d", &Num);
 
	if( (Sign = Num) < 0 )//��¼����
        Num = -Num;	//numȡ����ֵ
	i = 0;
	do{
        Str[ i ++ ] = Num % 2 + '0';//ȡ��һ������
	}while(( Num /= 2 ) > 0);//ɾ��������
	
	if( Sign < 0 )
        Str[ i ++ ] = '-';
	Str[i] = '\0'; //���ɵ�����������ģ�����Ҫ�������
	for (j = i - 1, i = 0; i < j; i ++, j --) 
		tmp = Str[i], Str[i] = Str[j], Str[j] = tmp; 
	printf("The string is \"%s\".\n", Str);
}
