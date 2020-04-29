#include <stdio.h>
#include <stdlib.h>

int* input(int n)
{
    int* a = (int *) malloc(n*sizeof(int)); //nuzhno ukazat' (int *) - malloc vozvrashyaet (void*)
    if (a == NULL)
    {
        printf("kernel panic\nwindows died\n");
        exit(666);
    }
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    return a;
}

void output (int n, int *a)
{
    for (int i = 0; i < n-1; ++i)
        printf("%d_", a[i]);
    printf("%d\n", a[n-1]);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int * b = input(n);
    output(n, b);
    return 0;
}

