#include <stdio.h>

void qsort(int* a, size_t n)
{
    if (n <= 1)
        return;
    int*k = partition(a, n);
    qsort(a, k-a);
    qsort(k, n-(k-a));
}

int main(void)
{
    printf("Hello World!\n");
    return 0;
}

