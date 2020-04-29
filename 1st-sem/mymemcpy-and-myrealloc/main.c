#include <stdio.h>

void mymemcpy(void *a, void *b, size_t size)
{
    char *c = (char*) a;
    char *d = (char*) b;
    for (size_t i = 0; i < size; ++i)
    {
        *(d+i) = *(c+i);
    }
}

void* myrealloc(void *a, size_t old_size, size_t new_size)
{
    void *b = malloc(new_size);
    if (b == NULL)
        exit(666);
    if (old_size > new_size)
        old_size = new_size;
    mymemcpy(b, a, old_size);
    free(a);
    return b;
}

int main(void)
{
    printf("Hello World!\n");
    return 0;
}

