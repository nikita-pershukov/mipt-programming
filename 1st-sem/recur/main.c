#include <stdio.h>

int f(int deep)
{
    if (deep == 1)
        return 1;
    return 2*f(deep-1)+1;
}

int factorial(int deep)
{
    if (deep == 1)
        return 1;
    return deep*factorial(deep-1);
}

int factorial_hvost(int deep, int res)
{
    if (deep == 1)
        return res;
    return factorial_hvost(deep-1, res*deep);
}

int fib(int n, int* count)
{
    ++(*count);
    if(n < 3)
        return 1;
    return (fib(n-1, count) + fib(n-2, count));
}

int main(void)
{
    int a, count = 0;
    scanf("%d", &a);
    a = fib(a, &count);
    printf("%d %d\n", a, count);
    return 0;
}

