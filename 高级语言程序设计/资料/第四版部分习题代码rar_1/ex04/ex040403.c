#include <stdio.h>
#include <stdlib.h>						// ����rand()����˵��
#include <time.h>

void main(void)
{
	int i, j, num[10], tmp;
	   
    // �õ�ǰʱ�����������������������ʹÿ���������ɲ�ͬ�������
	srand( (unsigned)time( NULL ) );

	for(i=0; i<10; i++) 				// ����10����
	{
        while(1) 						// ����1����
        {
			tmp=10 *rand()/RAND_MAX +1; // ���������
			for(j=0; j<i; j++) 			// �ж��Ƿ��ظ�
				if(tmp==num[j])
					break;
			if(j==i) 					// �ҵ�1����
			{
				num[i]=tmp; 			// �����
				break; 					// ��ʼ��һ��
			}
        }
        printf("%d,", num[i]); 			// ��ӡ���
	}
	printf("\b \n"); 
}
