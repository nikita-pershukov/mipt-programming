#include <stdio.h>

int check(int n)
{
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;
    if (n%2 == 0)
        return 0;
    if (n == 3)
        return 1;
    if (n%3 == 0)
        return 0;
    for (int i = 1; (6*i+1)*(6*i+1) <= n; ++i)
        if ((n % (6*i+1) == 0) || (n % (6*i-1) == 0))
            return 0;
    return 1;
}

int main(void)
{
//    int n;
//    scanf("%d", &n);
//    printf("%d\n", check(n));
    for(int n = 0; n < 1000; ++n)
        printf("%d %d\n", n, check(n));
    return 0;
}

