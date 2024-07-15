#include <stdio.h>
double p( double x, int n)
{
    if(n == 0)
        return 1.0;
    else
        if(n == 1)
            return x;
        else
            return ((2*n-1) * p(x, n-1) - (n-1) * p(x, n-2)) / n;
}
void main( void ) 	//添加主函数，验证p函数功能
{
    int n;
    double x;
    printf("input n, x:\n");
    scanf("%d,%lf", &n, &x);
    printf("p(%6.2lf, %d)=%6.2lf\n", x, n, p( x, n));
}
