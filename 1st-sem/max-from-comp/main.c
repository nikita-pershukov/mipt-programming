#include <stdio.h>

int comp(void* a, void* b)
{
    return *(int*)a - *(int*)b;
}

void *max (void* m, size_t size, size_t n, int (*comp)(void*, void*))
{
    char* input = m;
    int* res = input;
    for(int i = 0; i < n; ++i)
    {
        int check = 0;
        for(int j = 0; (j < size) && !check; ++j)
            if(comp(input+i*size+j, input+res+j))
            {
                check = 1;
                res = i*size;
            }
    }
}

int main(void)
{
    printf("Hello World!\n");
    return 0;
}

