#include <stdio.h>
#include <stdlib.h>

int* binsearch(int* m, size_t n, int a)
{
    if (!((a<*m)||(a>m[n-1])||!n))
    {
        size_t first = 0;
        size_t last = n;
        size_t mid = last/2;
        while (first < last)
        {
            if (a <= m[mid])
                last = mid;
            else
                first = mid+1;
            mid = first+(last-first)/2;
        }
        if (a == m[last])
            return m+last;
    }
    return NULL;
}

int main(void)
{
    size_t n;
    FILE* input = fopen("input.txt", "r");
    if (input == NULL)
        exit(666);
    fscanf(input, "%zd", &n);
    int* m = (int *) malloc (n*sizeof(int));
    if (m == NULL)
        exit(666);
    for(int i = 0; i < n; ++i)
        fscanf(input, "%d", &m[i]);
    int a;
    fscanf(input, "%d", &a);
    fclose(input);
    int* res = binsearch(m, n, a);
    FILE* output = fopen("output.txt", "w+");
    if (output == NULL)
        exit(666);
    fprintf(output, "#%d == %d\n", res, *res);
    fclose(output);
    return 0;
}

