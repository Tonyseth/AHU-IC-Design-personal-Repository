#include <stdio.h> 
void main( void )
{ 
    char String1[80], String2[80];
    short i=0, Differ;
    puts("�������һ���ַ�����");
    gets(String1); 
    puts("������ڶ����ַ�����");
    gets(String2);
    while ((String1[i]==String2[i]) && (String1[i]!='\0'))
        i++;
    Differ=String1[i]-String2[i];
    printf("%d\n", Differ);
}
