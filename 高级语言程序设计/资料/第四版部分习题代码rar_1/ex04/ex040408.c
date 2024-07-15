#include <stdio.h>
#include <string.h>
void main(void)
{ 
	char Str[100], Flag=1;
	int i, Len;
    puts("ÇëÊäÈë²âÊÔ×Ö·û´®£º");
	scanf("%s", Str);
	Len=strlen(Str);
	for(i=0; i<Len/2; i++)
		if(Str[i]!=Str[Len-1-i])
		{ 
			Flag=0;
			break;
		}
	if(Flag) 
		printf("Yes\n");
	else
		printf("No\n");
}
