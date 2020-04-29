#include <stdio.h>

int main(void)
{
    int a[4];
    for(int i = 0; i < 4; ++i)
        a[i] = 1;
    int n;
    scanf("%d", &n);
    for(int i = 3; i <n; ++i)
    {
            int b[3];
            for(int j = 0; j < 2; ++j)
                b[j] = a[j+1];
            a[3] = a[2]+a[1]+a[0];
            b[2] = a[3];
            for(int j = 0; j < 3; ++j)
                a[j] = b[j];
//        printf("%d %d\n", i, a[3]);
    }
    printf("%d\n", a[3]);
    return 0;
}

