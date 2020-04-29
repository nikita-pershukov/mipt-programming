#include <stdio.h>
#include <stdlib.h>

void myswap(int &a, int &b)
{
    int k = a;
    a = b;
    b = k;
}

int partition (int* a, int begin, int end)
{
    int i = begin;
    int j = end-1;
    if(begin == end - 1)
        if(a[begin] > a[end])
        {
            swap(a[begin], a[end]);
            return end;
        }
    while (i < j)
    {
        while ((a[i] < a[end]) && (i < end))
            ++i;
        while ((a[j] > a[end]) && (j > begin))
            --j;
        if(i < j)
            swap(a[i], a[j]);
    }
    swap(a[i], a[end]);
    return i;
}

int find_ind(int*a, int size, int ind)
{
    int part = partition(a, 0, size);
    if (part > ind)
        return find_ind(a, part - 1, ind);
    if (part < ind)
    {
        int delta = part + 1;
        return find_ind(a + delta, size - delta, ind - delta);
    }
    return a[ind];
}

double find_med(int*a, int size)
{
    return (size%2) ? find_ind(a, size-1, (size-1)/2) : ((find_ind(a, size-1, (size-1)/2) + find_ind(a, size-1, (size-1)/2 + 1) + 0.0)/2);
}

int main(void)
{
    int size;
    scanf("%d", &size);
    int* a = (int*) malloc(size*sizeof(int));
    if(a == NULL)
        exit(666);
    int min, max;
    for(int i = 0; i < size; ++i)
    {
        scanf("%d", &a[i]);
        if (i == 0)
        {
            min = a[i];
            max = a[i];
        }
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }
    printf("%d %.1f %d\n", min, find_med(a, size), max);
    return 0;
}

