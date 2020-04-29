#include <stdio.h>

void swap (int* a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    return;
}

int* partition (int* a, size_t n)
{
    int osnova = *(a+n/2);
    int i = 0;
    int j = n-1;
    while (i <= j)
    {
        while (a[i] < osnova)
            ++i;
        while (a[j] > osnova)
            --j;

        if(i <= j) {
            if (i < j)
                swap(a+i, a+j);
            i++;
            j--;
        }
    }
    if (i < n-1)
        partition(a+i, n-i);
    if (0 < j)
        partition(a, j);
    return a;
}

int main(void)
{
    printf("Hello World!\n");
    return 0;
}

