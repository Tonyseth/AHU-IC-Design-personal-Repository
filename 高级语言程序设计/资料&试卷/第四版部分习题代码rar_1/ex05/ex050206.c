#include <stdio.h>
#include <string.h>
void main(void)
{
    char s[][10]={"12", "23", "34", "45", "56"};
    char *s1[5], **s2=s1, s3[10];
    int i, j;

	for( i = 0; i < 5; i ++ )
        s1[i] = s[i];
    for(i = 0; i < 4; i ++)
        for(j = i+1; j < 5; j ++)
            if( strcmp(*(s2+i), *(s2+j))<0 )
            {
                strcpy( s3, *(s2+i) );
                strcpy( *(s2+i), *(s2+j) );
                strcpy( *(s2+j), s3 );
            }

    for( i = 0; i < 5; i ++ )
        printf("%s ", s1[i]);
}
