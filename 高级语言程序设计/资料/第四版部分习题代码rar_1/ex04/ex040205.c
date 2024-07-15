#include <stdio.h>
void main(void)
{
	char str[10]= "abcdef", tmp;
	int i, j;

	for( i = 1; i < 3; ++ i )
	{
		tmp = str[5];
		for( j = 4; j >= 0; -- j )
			str[j + 1] = str[j];
		str[0] = tmp;
	}

	printf("%s", str);
}
