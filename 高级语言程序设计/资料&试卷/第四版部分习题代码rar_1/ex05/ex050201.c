#include <stdio.h>
void main(void)
{
    int *var, ab;

    ab = 100; var = &ab; ab = *var + 10;

    printf("%d\n", *var);
}
