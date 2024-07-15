#include <stdio.h>
void main(void)
{
	int num;
	char StrNum[30]="请输入十进制整数：";
	int i, j, Num[20];
	printf(StrNum);
    scanf("%d", &num);
    for(i=0; num!=0; ++i)
    { 
		Num[i]=num%2;
		num/=2; 
	}
	for(j=0; j<i; ++j) 
        StrNum[j]= Num[i-j-1]>0 ? '1' : '0'; 
	StrNum[j]='\0'; 
	printf("转换成二进制串：");
	puts(StrNum);
}
