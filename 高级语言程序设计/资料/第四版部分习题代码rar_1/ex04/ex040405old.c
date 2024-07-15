//	编一个程序，输入一个字符按照从小到大顺序排列的字符串（长度<79）。再输入某个字符插入到该字符串中，
// 并保持该字符串中所有字符的原来顺序。最后输出新字符串。
#include <stdio.h>
#include <string.h>

void main(void) 
{
	char str[81], ch;
	int i, k=0, len;
	
	printf("请输入一个按照从小到大顺序排列的字符串（长度<79）:\n"); 
	gets(str);				//输入字符串
	printf("请输入插入的字符：\n");
	scanf("%c", &ch);		//输入待插入的字符     
	while(str[k]!='\0')		//寻找插入的位置，放在k中
	{	
		  if(ch<str[k])
			  break;
		  else
			  k++;
// 		  if(ch<str[k])
// 			  break;
// 		  k++;
	}
	len=strlen(str);		//计算字符串的长度
	for(i=len; i>=k; i--)	//将下标为k及其后面字符后移1个位置
		str[i]=str[i-1];
	str[k]=ch;				//在下标为k的位置上插入字符
	str[len+1]='\0';		//为插入字符后的字符串补充字符串结束标记符
	printf("%s\n", str);
}
