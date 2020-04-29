#include <stdio.h>
#include <stdlib.h>

long long int tre(int n, int* count, int* count_arr)
{
    ++(*count);
    ++(count_arr[n-1]);
//    printf("%lld\n", n);
    if (n < 4)
        return 1;
    return tre(n-1, count, count_arr) + tre(n-2, count, count_arr) + tre(n-3, count, count_arr);
}

void tri(int n, int deep, long long int a1, long long int a2, long long int a3)
{
    if (deep > n-2)
        return;
    printf("%d %d %zd\n", deep+2, deep, a1+a2+a3);
    tri(n, deep+1, a2, a3, a1+a2+a3);
}

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    int count = 0;
    int* count_arr = (int*) calloc(n,sizeof(int));
    if (count_arr == NULL)
        exit(666);
    long long res = tre(n, &count, count_arr);
    printf("%d %d %lld\n--------- call counter ---------\n", n, count, res);
    for(int i = 0; i < n; ++i)
        printf("%d %d\n", i+1, count_arr[i]);
    return 0;
}

