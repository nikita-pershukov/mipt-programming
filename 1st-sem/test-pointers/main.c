#include <stdio.h>

void check(int *a, int *b)
{
    if (*a < *b)
    {
        int c = *a;
        *a = *b;
        *b = c;
    }
}

int main(void)
{
    int d, e;
    scanf("%d%d", &d, &e);
    check(&d, &e);
    printf("%d %d\n", d, e);
    return 0;
}

