// Program: EG0203.C 
// Description: 已知三角形三条边a,b,c，求三角形面积s。
#include <stdio.h>
#include <math.h>

void main (void)
{
    float a=3, b=4, c=6; 
    float p, s;

    p = (a + b + c) / 2;
    s = sqrt (p * (p - a) * (p - b) * (p - c));

    printf ("S(%1.0f, %1.0f, %1.0f)=%6.2f\n", a, b, c, s);
}
