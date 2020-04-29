#include <stdio.h>

int main(void)
{
    char c = '(';
    int open = 0;
    while((c == '(') || (c == ')'))
    {
        scanf("%c", &c);
        if (c == '(')
            open++;
        if (c == ')')
        {
            if (open)
                open--;
            else
            {
                printf("---------error---------\n");
                return 0;
            }
        }
    }
    if (open)
    {
        printf("---------error---------\n");
        return 0;
    }
    printf("---------success---------\n");
    return 0;
}

