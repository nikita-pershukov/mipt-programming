#include <stdio.h>
#include <math.h>

int main(void)
{
    for(int n = 1; n < 1000000; n*=10)
    {
        //    scanf("%d", &n);
        double res_d_b = 0;
        double res_d_e = 0;
        float res_f_b = 0;
        float res_f_e = 0;
        for(int i = 1; i <= n; ++i)
        {
            res_d_b += (1+0.0)/(i*i);
            res_f_b += (1+0.0)/(i*i);
        }
        for(int i = n; i > 0; --i)
        {
            res_d_e += (1+0.0)/(i*i);
            res_f_e += (1+0.0)/(i*i);
        }
        printf("---------%d---------\n", n);
        printf("res_d_b %e\n", res_d_b);
        printf("res_f_b %e\n", res_f_b);
        printf("res_d_e %e\n", res_d_e);
        printf("res_f_e %e\n", res_f_e);
        printf("delta_d_b %e\n", res_d_b-(M_PI*M_PI+0.0)/6);
        printf("delta_f_b %e\n", res_f_b-(M_PI*M_PI+0.0)/6);
        printf("delta_d_e %e\n", res_d_e-(M_PI*M_PI+0.0)/6);
        printf("delta_f_e %e\n", res_f_e-(M_PI*M_PI+0.0)/6);
    }
    printf("SUMM %e\n", (M_PI*M_PI+0.0)/6);
    return 0;
}

