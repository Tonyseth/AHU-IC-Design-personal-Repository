// Program: EG0320.c
// Description: °ÙÔªÂò°Ù¼¦
#include <stdio.h>
void main( void )
{ 
	unsigned char cock, hen, chicken;

	for( cock = 0; cock <= 100; cock ++ )
		for( hen = 0; hen <= 100; hen ++ )
			for( chicken = 0; chicken <= 100; chicken ++ )
			{
				if( cock + hen + chicken == 100 &&
					5 * cock+ 3 * hen + chicken / 3.0 == 100 )
					printf("cocks=%d, hens=%d, chickens=%d\n",
					        cock, hen, chicken);
			}
}
