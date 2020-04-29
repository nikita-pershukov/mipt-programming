#include <stdio.h>

int fectorial(int n)
{
    if (!n)
        return 1;
    return n*factorial(n-1);
}

int main(void)
{
    printf("Hello World!\n");
    return 0;
}

