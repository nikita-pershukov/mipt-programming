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
	int n;
	scanf("%d", &n);
	int* a = (int*) malloc(sizeof(int)*n);
	check_NULL(a);
	a[0]=1;
	for(int i = 1; i < n+1; ++i)
	{
		a[i]=0;
		for(int j = i-1; (j > -1) && (j > i-7); --j)
			a[i]+=a[j];
	}
	printf("---%d: %d---\n", n, a[n-1]);
	return 0;
}

