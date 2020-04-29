#include <stdio.h>

int main(void)
{

    //reading

    int a[2][4];
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 4; ++j)
            a[i][j] = (i+1)*(j+1);

    int b[4][5];
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 5; ++j)
            b[i][j] = (i+1)*(j+1);

    //solution

    int res[2][5];
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 5; ++j)
        {
            res[i][j] = 0;
                for (int m = 0; m < 4; ++m)
                    res[i][j] += a[i][m]*b[m][j];
        }

    //result

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 4; ++j)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("------------\n");
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 5; ++j)
            printf("%d ", b[i][j]);
        printf("\n");
    }
    printf("------------\n");
    printf("------------\n");
    printf("------------\n");
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 5; ++j)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}

