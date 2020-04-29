#include <stdio.h>
#include <stdlib.h>

void check_NULL(void* pointer)
{
	if (pointer == NULL)
	{
		printf("Erroe\n");
		exit(666);
	}
	return;
}

int get_brackets_count(int n)
{
    int* a = (int*) malloc((n+1)*sizeof(int));
    check_NULL(a);
    for(int i = 0; i < (n+1); ++i)
        a[i] = 0;
    a[0] = 1;
    for(int i = 1; i < (n+1); ++i)
        for(int j = 0; j < i; ++j)
            a[i] += a[j]*a[i-1-j];
    int res = a[n];
    free(a);
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d %d\n", n, get_brackets_count(n));
    return 0;
}
