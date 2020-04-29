#include <stdio.h>

int nok(int a, int b)
{
    int res = a;
    if (b>a)
    {
        res = b;
        int draft = b;
        b = a;
        a = draft;
    }
    int i;
    for (i = 1; (a*i)%b != 0; ++i);
    return a*i;
}

int nod(int a, int b)
{
    int res = a;
    if (b<a)
    {
        res = b;
        int draft = b;
        b = a;
        a = draft;
    }
    if (b % a == 0)
        return a;
    int j = 1;
    for (int i = 2; b%(a/j)!=0; ++i)
        if (!(a%i))
            j = i;
    return a/j;
}

int main(void)
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d %d\n", nok(a,b), nod(a,b));
    return 0;
}

