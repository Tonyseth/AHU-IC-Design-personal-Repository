#include <stdio.h>
void main(void)
{
	int Matrix[3][3]={	{68,55,28},
						{36,45,17},
						{77,16,24}  };
	int i, j, maxi, maxj;
	maxi=0, maxj=0;
	for (i=0; i<3; i++)
		for(j=0; j<3; j++)
			if(Matrix[maxi][maxj]<Matrix[i][j])
				maxi=i, maxj=j;
	printf("最大值：%d，位于第%d行，第%d列\n", Matrix[maxi][maxj], maxi+1, maxj+1);
}
