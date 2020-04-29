#include <stdio.h>

int main(void)
{

    //proverka na vlozhenost'
    int r = 1;
    for (int i = 0; (i < n) && r; ++i)
        for (int j = i; (j < n) && r; ++j)
            if(!( ((x[i]<=x[j]) && (y[i]>=y[j])) || ((x[i]>=x[j]) && (y[i]<=y[j]))))
                r = 0;
    printf("Hello World!\n");
    return 0;
}

