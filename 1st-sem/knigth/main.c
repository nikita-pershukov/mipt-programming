#include <stdio.h>

int main(void)
{
    int n, res = 0;
    scanf("%d", &n);
    int *a = (int*)malloc(n*sizeof(int));
    int *b = (int*)malloc(n*sizeof(int));
    b[0] = 1;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        if (i)
            b[i] = b[i-1] ? a[i]:!a[i];
    }
    int check = (b[0] == (b[n-1] ? a[0]:!a[0]));
    for (int i = 0; i < n; ++i)
    {
        if (check ? b[i] : !b[i])
            ++res;
    }
    if (res > n/2)
        res = n - res;
    printf("%d\n", res);
    return 0;
}

