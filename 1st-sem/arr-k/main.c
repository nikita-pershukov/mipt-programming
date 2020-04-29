#include <stdio.h>

int main(void)
{
    int ar_name[1000];
    int n,i,a,k;
    scanf("%d",&n);
    for (i=0;i<n; i++)
    {
        scanf("%d",&a);
        ar_name[i]=a;
    };
    scanf("%d",&k);
    k = k%n;
    for (i=n-k; i<n; i++)
    {
        printf("%d",ar_name[i]);
        printf(" ");
    }
    for (i=0; i<n-k; i++)
    {
        printf("%d",ar_name[i]);
        printf(" ");
    };
    getchar();
    getchar();
    return 0;
}
