// Program: EG0309.C
// Description: �Ӽ�������һ���ٷ��Ƴɼ�,���㲢����弶�Ƿ��Ƶȼ�
#include <stdio.h>
void main( void )
{
	int score;

	printf("������һ���ٷ��Ƴɼ�:");
	scanf("%d", &score );

	switch( score / 10 )
     /*float score;
     printf("������һ���ٷ��Ƴɼ�:");
     scanf("%f", &score );
     switch( (int)score / 10 )*/
	{
	case 10:
	case 9:
		printf("A\n");
		break;
	case 8:
		printf("B\n");
		break;
	case 7:
		printf("C\n");
		break;
	case 6:
		printf("D\n");
		break;
	case 5:
	case 4:
	case 3:
	case 2:
	case 1:
	case 0:
		printf("E\n");
		break;
	default:
		printf("����ĳɼ�����\n");
	}
}
