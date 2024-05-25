// Program: EG0710.C 
// Description: 共用体的应用示范
#include <stdio.h>
void main( void )
{
	struct
	{
		char name[10];
		int age;
		char job;
		union
		{
			int class;
			char office[10];
		} depa;
	} employ[5];
	int i;

	printf("input name, age, job and department\n");
	for( i = 0; i < 5; i ++ )
	{
		scanf("%s%d%c", employ[i].name, &employ[i].age, &employ[i].job);
		if( employ[i].job == 's' )
			scanf("%d", &employ[i].depa.class);
		else
			scanf("%s", employ[i].depa.office);
	}
	printf("name\tage job class/office\n");
	for( i = 0; i < 5; i ++ )
	{
		if( employ[i].job == 's' )
			printf("%s\t%3d%3c\t%d\n", employ[i].name, employ[i].age,
			employ[i].job, employ[i].depa.class);
		else
			printf("%s\t%3d%3c\t%s\n", employ[i].name, employ[i].age,
			employ[i].job, employ[i].depa.office);
	}
}
