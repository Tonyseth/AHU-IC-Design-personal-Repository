#include <stdio.h>
// #include <string.h>
void main(void)
{ 
	char Str[100];
	int i, j;
    puts("ÇëÊäÈë²âÊÔ×Ö·û´®£º");
	scanf("%s", Str);
	i=j=0; 
	while(Str[j])
		j++;
	j--;
	while(i<j)
	{
		if(Str[i]!=Str[j])
			break;
		i++, j--;
	}
	if(i>=j) 
		printf("Yes\n");
	else
		printf("No\n");
}
