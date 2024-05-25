// Program: EG0812.C 
// Description: 输入5名职工信息，存储到file7.dat中，查找并打印总工资最高的职工信息
#include <stdio.h>
#include <stdlib.h>
struct person                              // 定义职工工资的结构体及结构体变量 
{
	int  no;                               // 编号 
	char name[16];                         // 姓名 
	int  wage1;                            // 基本工资 
	int  wage2;                            // 职务工资 
	int  wage3;                            // 岗位工资 
	int  wage;                             // 总工资
};
void main( void )
{ 
	FILE *fp;
	struct person Worker, MaxWorker;
	int i;

	if( ( fp = fopen( "file7.dat", "wb" ) ) == NULL )	// 打开只写二进制文件 
	{
		printf("File can not open!\n");
		exit( 0 );
	}
	// 输入5名职工的信息，写到fp指向的文件中
	for ( i = 0; i < 5; i ++ )	             
	{
		scanf("%d", &Worker.no);            // 输入编号 
		scanf("%s", Worker.name);           // 输入姓名 
		scanf("%d", &Worker.wage1);         // 输入基本工资 
		scanf("%d", &Worker.wage2);         // 输入职务工资 
		scanf("%d", &Worker.wage3);         // 输入岗位工资 
		Worker.wage = Worker.wage1 + Worker.wage2 + Worker.wage3;// 计算总工资 
		fwrite( &Worker, sizeof( struct person ), 1, fp );// 将当前职工信息写到fp指向的文件中
	}
	fclose( fp );	// 关闭fp所指向的文件 

	MaxWorker.wage = Worker.wage;
	if( ( fp = fopen( "file7.dat", "rb" ) ) == NULL ) // 打开只读文件
	{
		printf("File can not open!\n");
		exit( 0 );
	}
	while( !feof( fp ) )                    // fp不是文件尾，则继续查找 
	{
		// 读取文件中当前1个职工信息存入结构体变量s1
		fread( &Worker, sizeof(struct person), 1, fp );
		if( MaxWorker.wage < Worker.wage )  // 判断并记录新的最高工资和其职工编号 
			MaxWorker = Worker;
	}
	fclose( fp );                           // 关闭fp所指向的文件 

	if( ( fp = fopen( "file7.dat", "rb" ) ) == NULL ) // 打开只读文件 
	{
		printf("File can not open!\n");
		exit( 0 );
	}
	while( !feof( fp ) )                    // fp不是文件尾，则继续查找 
	{
		// 从文件中读取当前的1个职工信息存入结构体变量Worker
		fread( &Worker, sizeof(struct person), 1, fp );
		if( Worker.wage == MaxWorker.wage ) // 查找、输出最高工资职工的信息
			printf("max:%d,%s,%d,%d,%d,%d\n", Worker.no, Worker.name, 
			        Worker.wage1, Worker.wage2, Worker.wage3, Worker.wage);
	}
	fclose( fp );                           // 关闭fp所指向的文件 
}
