// Program: EG0412.C 
// Description: 不用库函数，将一个输入的整数转换为字符串。
#include <stdio.h>
void main( void )
{
    char Str[20], tmp;
    short Num, i, j, Sign; 
 
    printf("输入一个整数:");
	scanf("%d", &Num);
 
	if((Sign=Num)<0)//记录负号
        Num=-Num;	//num取绝对值
	i=0;
	do{
        Str[i++]=Num%10+'0';//取下一个数字
	}while ((Num/=10)>0);//删除该数字
	
	if(Sign<0)
        Str[i++]='-';
	Str[i] = '\0'; //生成的数字是逆序的，所以要逆序输出
	for (j = i-1, i = 0; i < j; i++, j--) 
		tmp = Str[i], Str[i] = Str[j], Str[j] = tmp; 
	printf("The string is \"%s\".\n", Str );
}
