#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct request
{
	int begin;
	int end;
};

void check_NULL(void* pointer)
{
	if (pointer == NULL)
	{
		printf("Error!\n");
		exit(666);
	}
	return;
}

void swap(void* a, void* b, int size)
{
	void* c = malloc(size);
	check_NULL(c);
	memmove(c, a, size);
	memmove(a, b, size);
	memmove(b, c, size);
	free(c);
	return;
}

void swap_int(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
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

int compare_request(const void* a, const void* b)
{
	return ((struct request*)a)->end-((struct request*)b)->end;
}

void insertsort(void* arr, int n, int size, int (*compare)(const void *a, const void* b))
{
	if (n == 1)
		return;
	char* a = (char*) arr;
	for(int i = 0; i < n; ++i)
		for(int j = i-1; j > -1; --j)
			if (compare(a+(j+1)*size, a+j*size) < 0)
				swap(a+j*size, a+(j+1)*size, size);
	return;
}

int main()
{
	int begin, end, n;
	scanf("%d %d", &begin, &end);
	scanf("%d", &n);
	struct request* a = (struct request*) malloc(n*sizeof(struct request));
	for(int i = 0; i < n; ++i)
		scanf("%d %d", &(a[i].begin), &(a[i].end));
	insertsort(a, n, sizeof(struct request), compare_request);
	int i = begin;
	int j = 0;
	int count = 0;
    for(j = 0; j < n; ++j)
		if (i <= a[j].begin)
		{
            i = a[i].end;
            count++;
        }
    if (i > end)
		--count;
	printf("%d\n", count);
	return 0;
}
