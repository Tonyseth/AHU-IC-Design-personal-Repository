// ����һ���ַ������ַ�������ĸ�����ֵ���ϣ����ʵ�����һ���µ��ַ�����
// Ҫ����ĸ��ǰ�棬�����ں��棬˳�򲻱䣬���磺2s7ess83a ���sessa2783 
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
