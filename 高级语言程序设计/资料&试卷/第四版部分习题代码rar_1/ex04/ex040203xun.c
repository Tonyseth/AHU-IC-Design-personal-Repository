#include <stdio.h>
void main(void)
{
    int aa[100], n, i, k;
    for(n=0, i=1; i<=100; i++)
		if(i%7==0 && i%11 || i%7 && i%11==0)
			aa[n++]=i;
	for(k=0; k<n; k++)
	{
		printf("%5d", aa[k]);
		if((k+1)%10 == 0)
			printf("\n");
	}


/*���ǿα��ϵĵĳ���û�����aa[9]��aa[19]��
		if((k+1)%10 == 0)
			printf("\n");
		else
			printf("%5d", aa[k]);
*/
  }
