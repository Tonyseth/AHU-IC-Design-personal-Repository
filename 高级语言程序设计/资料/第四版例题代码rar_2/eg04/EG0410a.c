// Program: EG0410a.C
// Description: 最牛的约瑟夫问题数学解法
#include <stdio.h>
void main( void )
{    
     int n, m, i, s=0;
     printf("N M = ");
     scanf("%d%d", &n, &m);
     for( i = 2; i <= n; i ++ )
          s = (s + m ) % i;
     printf("The winner is %d\n", s + 1);
}
