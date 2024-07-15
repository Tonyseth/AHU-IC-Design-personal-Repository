#include <stdio.h>
void main(void)
{
	int Matrix[3][3]={	{68,55,28},
						{36,45,17},
						{77,16,24}  };
	int i, j, max, maxi, maxj;
	max=Matrix[0][0], maxi=1, maxj=1;
	for (i=0; i<3; i++)
		for (j=0; j<3; j++)
			if(max<Matrix[i][j])
				max=Matrix[i][j], maxi=i+1, maxj=j+1;
	printf("最大值：%d，位于第%d行，第%d列\n", max, maxi, maxj);
}
