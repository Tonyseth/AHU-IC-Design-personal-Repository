// ���ʵ�֣�����һ��һά��������10������������ڵ�����ƽ��ֵ������Ԫ�ظ�����
// ������: 10 20 40 32 67 56 75 88 93 100
// ���: 5
#include <stdio.h>
void main( void )
{
	int Num[10], i, j=0, Sum=0;
	double  Avg;//Avg:ƽ��ֵ
	
	for( i = 0; i < 10; i ++ )
	{
		scanf("%d", &Num[i]);
		Sum += Num[i];
	}
	Avg = ( double )Sum / 10;
	for( i = 0; i < 10; i ++ )
		if( Num[i] > Avg )//��ƽ��ֵ�ߵ�+1
			j = j + 1;
	
	printf("%d", j);
}

