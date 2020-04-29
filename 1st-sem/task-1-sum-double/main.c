#include <stdio.h>

int main(void)
{
    double res_abs = 0;
    double res = 0;
    int n;
    double c = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        double y = 0;
        scanf("%lf", &y);
        res += y;
        y += c;
        double t = res_abs + y;
        c = (t - res_abs) - y;
        res_abs = t;
    }
    printf("%e - res\n%e - res_abs\n%e - delta\n", res, res_abs, res_abs-res);
    return 0;
}
