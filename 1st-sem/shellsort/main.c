#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void check_NULL(void* pointer)
{
	if (pointer == NULL)
	{
		printf("Erroe\n");
		exit(666);
	}
	return;
}

int compare_int(const void* a, const void* b)
{
	int a_int = *((int*)a);
	int b_int = *((int*)b);
	if (a_int > b_int)
		return 1;
	if (a_int < b_int)
		return -1;
	return 0;
}

int compare_double(const void* a, const void* b)
{
	double a_d = *((double*)a);
	double b_d = *((double*)b);
	if (a_d > b_d)
		return 1;
	if (a_d < b_d)
		return -1;
	return 0;
}

int get_k(int n)
{
	int i = 0;
	long long int st = 1;
	while((2*(st-1)) < n)
	{
		st <<= 1;
		++i;
	}
	return i;
}

long long int hib(int k)
{
	int res = 1;
	for(int i = 0; i < k; ++i)
		res <<= 1;
	return res-1;
}

void shellsort(void* arr, int n, int size, int(*compare)(const void*
a, const void* b))
{
	char* a = (char*) arr;
	int i, j, d, k_max = get_k(n);
	char* x = (char*) malloc(sizeof(char));
	for(int k=k_max; k > 0; k++)
	{
		d = hib(k);
		for(i=d; i < n; ++i)
		{
			memmove(x, a+i*size, size);
			for(j=i-d; (compare(x, a+j*size) < 0) && (j >= 0); j-=d)
				memmove(a+(j+d)*size, a+j*size, size);
			memmove(a+(j+d)*size, x, size);
		}
	}
	free(x);
	return;
}

int main()
{
	int n;
	scanf("%d", &n);
	int* a = (int*) malloc(n*sizeof(int));
	check_NULL(a);
	for(int i = 0; i < n; ++i)
		scanf("%d", &(a[i]));
	shellsort(a, n, sizeof(int), compare_int);
	for(int i = 0; i < n; ++i)
		printf("%d\n", a[i]);
	
	free(a);
	return 0;
}
