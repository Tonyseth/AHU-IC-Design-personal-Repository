// Program: EG0812.C 
// Description: ����5��ְ����Ϣ���洢��file7.dat�У����Ҳ���ӡ�ܹ�����ߵ�ְ����Ϣ
#include <stdio.h>
#include <stdlib.h>
struct person                              // ����ְ�����ʵĽṹ�弰�ṹ����� 
{
	int  no;                               // ��� 
	char name[16];                         // ���� 
	int  wage1;                            // �������� 
	int  wage2;                            // ְ���� 
	int  wage3;                            // ��λ���� 
	int  wage;                             // �ܹ���
};
void main( void )
{ 
	FILE *fp;
	struct person Worker, MaxWorker;
	int i;

	if( ( fp = fopen( "file7.dat", "wb" ) ) == NULL )	// ��ֻд�������ļ� 
	{
		printf("File can not open!\n");
		exit( 0 );
	}
	// ����5��ְ������Ϣ��д��fpָ����ļ���
	for ( i = 0; i < 5; i ++ )	             
	{
		scanf("%d", &Worker.no);            // ������ 
		scanf("%s", Worker.name);           // �������� 
		scanf("%d", &Worker.wage1);         // ����������� 
		scanf("%d", &Worker.wage2);         // ����ְ���� 
		scanf("%d", &Worker.wage3);         // �����λ���� 
		Worker.wage = Worker.wage1 + Worker.wage2 + Worker.wage3;// �����ܹ��� 
		fwrite( &Worker, sizeof( struct person ), 1, fp );// ����ǰְ����Ϣд��fpָ����ļ���
	}
	fclose( fp );	// �ر�fp��ָ����ļ� 

	MaxWorker.wage = Worker.wage;
	if( ( fp = fopen( "file7.dat", "rb" ) ) == NULL ) // ��ֻ���ļ�
	{
		printf("File can not open!\n");
		exit( 0 );
	}
	while( !feof( fp ) )                    // fp�����ļ�β����������� 
	{
		// ��ȡ�ļ��е�ǰ1��ְ����Ϣ����ṹ�����s1
		fread( &Worker, sizeof(struct person), 1, fp );
		if( MaxWorker.wage < Worker.wage )  // �жϲ���¼�µ���߹��ʺ���ְ����� 
			MaxWorker = Worker;
	}
	fclose( fp );                           // �ر�fp��ָ����ļ� 

	if( ( fp = fopen( "file7.dat", "rb" ) ) == NULL ) // ��ֻ���ļ� 
	{
		printf("File can not open!\n");
		exit( 0 );
	}
	while( !feof( fp ) )                    // fp�����ļ�β����������� 
	{
		// ���ļ��ж�ȡ��ǰ��1��ְ����Ϣ����ṹ�����Worker
		fread( &Worker, sizeof(struct person), 1, fp );
		if( Worker.wage == MaxWorker.wage ) // ���ҡ������߹���ְ������Ϣ
			printf("max:%d,%s,%d,%d,%d,%d\n", Worker.no, Worker.name, 
			        Worker.wage1, Worker.wage2, Worker.wage3, Worker.wage);
	}
	fclose( fp );                           // �ر�fp��ָ����ļ� 
}
