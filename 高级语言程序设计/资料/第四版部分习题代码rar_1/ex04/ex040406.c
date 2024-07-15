#include <stdio.h> 
void main( void )
{ 
    char String1[80], String2[80];
    short i=0, Differ;
    puts("请输入第一个字符串：");
    gets(String1); 
    puts("请输入第二个字符串：");
    gets(String2);
    while ((String1[i]==String2[i]) && (String1[i]!='\0'))
        i++;
    Differ=String1[i]-String2[i];
    printf("%d\n", Differ);
}
