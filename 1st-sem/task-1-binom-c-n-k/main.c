#include <stdio.h>

int nod(int a, int b)
{
    int c;
//    if (a > b)
//    {
//        c = a;
//        a = b;
//        b = c;
//    }
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int k_check(int n, int* k)
{
    if (*k > n/2)
        *k = n - *k;
    return *k;
}

int c_n_k(int n, int k)
{
    int p = 1;
    int q = 1;
    while(n > 1)
    {
        p *= n;
        q *= n - k_check(n, &k);
        int sokr = nod(p, q);
        p /= sokr;
        q /= sokr;
        --n;
    }
    return p;
}

int main(void)
{
    int n, k;
    scanf("%d %d", &n, &k);
    if ((n < 1) || (k < 0))
    {
        printf("K>=0 && N>0\n");
        exit(666);
    }
    if (k > n)
    {
        printf("K must be less then N\n");
        exit(666);
    }
    printf("%d\n", c_n_k(n, k));
    return 0;
}

