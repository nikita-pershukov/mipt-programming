#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_NULL(void* ukaz)
{
    if (ukaz == NULL)
        exit(666);
    return;
}

int* merge(int* a, int* b, size_t sizea, size_t sizeb)
{
    int* c = (int*) malloc((sizea+sizeb)*sizeof(int));
    check_NULL(c);
    int i = 0;
    int j = 0;
    while((i < sizea) && (j < sizeb))
        if (a[i] < b[j])
        {
            c[i+j] = a[i];
            ++i;
        }
        else
        {
            c[i+j] = b[j];
            ++j;
        }
    if(i <= sizea)
        memcpy(c+i+j, a+i, sizea-i);
    if(j <= sizeb)
        memcpy(c+i+j, b+j, sizeb-j);
    free(a);
    free(b);
    return c;
}

int main(void)
{
    size_t sizea, sizeb;
    scanf("%zd", &sizea);
    int* a = (int*) malloc(sizea*sizeof(int));
    for(int i = 0; i < sizea; ++i)
        scanf("%d", &a[i]);
    scanf("%zd", &sizeb);
    int* b = (int*) malloc(sizeb*sizeof(int));
    for(int i = 0; i < sizeb; ++i)
        scanf("%d", &b[i]);
    size_t sizec = sizea+ sizeb;
    printf("%zd\n", sizec);
    int* c = merge(a, b, sizea, sizeb);
    for(int i = 0; i < sizec; ++i)
        printf("%d ", c[i]);
    printf("\n");
    free(c);
    return 0;
}

