#include <stdio.h>

int main(void)
{
    double a, b, c, d, x, x1;
    scanf("%lg", &a);
    scanf("%lg", &b);
    scanf("%lg", &c);
    d=b*b-4*a*c;
    if (a!=0)
    {
        if (d<0)
            printf ("NO");
        else if (d==0)
        {
            x=(-b)/(2*a);
            if (x == -0)
                x = 0;
            printf("%lg", x);
        }
        else
        {
            if ((b==0)&&(c==0))
                printf("0");
            else
            {
                x=(-b+sqrt(d))/(2*a);
                x1=(-b-sqrt(d))/(2*a);
                if (x == -0)
                    x = 0;
                if (x1 == -0)
                    x1 = 0;
                if (x<x1)
                    printf("%lg %lg",x, x1);
                else
                    printf("%lg %lg",x1, x);
            }
        }
    }
    else
    {
        if ((c==0)&&(b==0))
            printf("R");
        else
        {
            if (b==0)
                printf("NO");
            else
            {
                x=(-c)/b;
                if (x == -0)
                    x = 0;
                printf("%lg", x);
            }
        }
    }
    return 0;
}


