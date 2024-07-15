#include <stdio.h>
#include <string.h>
void main(void)
{ 
	char Str1[80], Str2[80];
	short n, j, k, Str1Len;
	puts("请输入一个字符串（长度<80）：");
	gets(Str1); 
	puts("请输入n：");
	scanf("%d", &n); 
	Str1Len=strlen(Str1);
	if(Str1Len<n)
	{
		puts("字符串没有%d个字符\n", n);
	} 
	else
	{
		for(j=0, k=Str1Len-n; Str1[k]; j++, k++)
			Str2[j]=Str1[k];
		Str2[j]='\0';
		printf("新字符串为%s\n", Str2); 
	}
}
