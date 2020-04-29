#include <stdio.h>
#include <stdlib.h>

void check_NULL(void* pointer)
{
	if (pointer == NULL)
	{
		printf("Error!\n");
		exit(666);
	}
	return;
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int* a = (int*) malloc(sizeof(int)*(n+1));
	check_NULL(a);
	a[0]=0;
	int* b = (int*) malloc(sizeof(int)*(n+1));
        check_NULL(b);
        b[0]=1;
	int* m = (int*) malloc(sizeof(int)*n);
        check_NULL(m);
	for(int i = 0; i < k; ++i)
		scanf("%d", &(m[i]));
	for(int i = 1; i < n+1; ++i)
	{
		a[i]=a[i-1]+1;
		b[i]=1;
		for(int j = 0; j < k; ++j)
			if ((i-m[j]) > -1)
				if((a[i-m[j]]+1)<a[i])
				{
					a[i]=a[i-m[j]]+1;
					b[i]=m[j];
				}
		printf("%d %d %d\n", i, a[i], b[i]);
	}
	printf("---%d: %d---\n----------------------------\n", n, a[n]);
	int i = 0;
	int j = n;
	int* res = (int*) calloc(a[n], sizeof(int));
	while(j>0)
	{
		printf("%d %d\n", j, b[j]);
		res[i]=b[j];
		++i;
		j -= b[j];
	}
	for(i = a[n]-1; i > -1; --i)
		if(res[i])
			printf("%d", res[i]);
	printf("\n");
	return 0;
}


