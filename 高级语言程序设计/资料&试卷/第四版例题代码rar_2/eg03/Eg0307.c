// Program: EG0307.C
// Description: ����һԪ���η��̵�����ϵ��a��b��c,Ҫ����㲢��ӡ�����̵�����ʵ������
#include <stdio.h>
#include <math.h>

void main (void)
{
	double a, b, c, deta, deta2, root1, root2;

	printf ("������һԪ���η��̵�����ϵ��a, b, c:");
	scanf ("%lf,%lf,%lf", &a, &b, &c );

	deta = b * b-4 * a * c;
	if ( deta < 0 )
		printf("����û��ʵ������\n");
	else
		if( deta == 0 )
			printf ("������������ȵĸ��� %5.2lf\n", - b / 2 / a );
		else
		{
			deta2 = sqrt(deta);
			root1 = ( - b + deta2 ) / 2 / a;
			root2 =  (- b - deta2 ) / 2 / a;
			printf ("Root1= %5.2lf Root2=%5.2lf\n", root1, root2 );
		}
}
