#include <stdio.h>
#include <string.h>
void main(void)
{ 
	char Str1[80], Str2[80];
	short n, j, k, Str1Len;
	puts("������һ���ַ���������<80����");
	gets(Str1); 
	puts("������n��");
	scanf("%d", &n); 
	Str1Len=strlen(Str1);
	if(Str1Len<n)
	{
		puts("�ַ���û��%d���ַ�\n", n);
	} 
	else
	{
		for(j=0, k=Str1Len-n; Str1[k]; j++, k++)
			Str2[j]=Str1[k];
		Str2[j]='\0';
		printf("���ַ���Ϊ%s\n", Str2); 
	}
}
