// 输入一个字符串，字符串是字母和数字的组合，编程实现输出一个新的字符串，
// 要求字母在前面，数字在后面，顺序不变，例如：2s7ess83a 变成sessa2783 
#include <stdio.h>
void main( void )
{
    char str[80], tmp;
    int i, j, len;
	
	gets(str);
	
	for(len=0; str[len]; ++len);
	
    for(i=0; i<len; ++i)
    {
		if ('0'<=str[i] && str[i]<='9')
		{
			tmp=str[i];
			for(j=i; str[j]; ++j)
				str[j]=str[j+1];
			str[j-1]=tmp;
			len--;
		}
    }
    printf("%s", str);
}
