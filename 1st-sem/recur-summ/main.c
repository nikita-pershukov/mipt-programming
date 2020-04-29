#include <stdio.h>
#include <stdlib.h>

int quicksumm(double *a, size_t size)
{
    if (size == 1)
        return *a;
    return (quicksumm(a, size/2) + quicksumm(a+size/2, size-size/2));
}

int main(void)
{
    int n;
    scanf("%d", &n);
    double *a = (double*) malloc(n*sizeof(double));
    if (a == NULL)
        exit(666);
    for(int i = 0; i < n; ++i)
        scanf("%lf", &a[i]);
    printf("%d\n", quicksumm(a, n));
    return 0;
}

