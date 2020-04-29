#include <stdio.h>

int main(void)
{
    struct coor
    {
        int x, y;
    };
    struct coor input[3];
    for (int i = 0; i < 3; ++i)
    {
        scanf("%d%d", &input[i].x, &input[i].y);
        if (input[i].x > input[i].y)
        {
            int draft = input[i].x;
            input[i].x = input[i].y;
            input[i].y = draft;
        }
    }
    int k = 0;
    for (int i = 0 ; i < 3; ++i, ++k)
    {
        int l = k;
        for (int j = k; j < 3; ++j)
            if (input[j].x < input[l].x)
                l = j;
            else
                if ((input[j].x == input[l].x) && (input[j].y > input[l].y))
                    l = j;
        struct coor draft = input[k];
        input[k] = input[l];
        input[l] = draft;
    }
    int check = 1;
    for (int i = 0; (i < 2) && check; ++i)
        if ((input[i].x > input[i+1].x) || (input[i].y < input[i+1].y) || ((input[i].x == input[i+1].x) && (input[i].y == input[i+1].y)))
            check = 0;
    if (check)
        printf("YES\n");
    else
        printf("NO\n");
    getchar();
    return 0;
}

