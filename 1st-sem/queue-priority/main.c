#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1024

struct element
{
	int key;
	int priority;
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

int compare_str(const void* a, const void* b)
{
	char* a_str = *((char**)a);
	char* b_str = *((char**)b);
	return strcmp(a_str, b_str);
}

int compare_priority(const void* a, const void* b)
{
	struct element a_el = *((struct element*)a);
	struct element b_el = *((struct element*)b);
	return a_el.priority - b_el.priority;
}

void heapify(void* arr, int i, int n, int size, int (*compare)(const
void* a, const void* b))
{
    char* a = (char*) arr;
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i;
    if ((left < n) && (compare(a+left*size, a+largest*size) > 0))
        largest = left;
    if ((right < n) && (compare(a+right*size, a+largest*size) > 0))
        largest = right;
    if (largest != i)
    {
        swap(a+i*size, a+largest*size, size);
        heapify(a, largest, n, size, compare);
    }
    return;
}

void buildheap(void* arr, int n, int size, int (*compare)(const void*
a, const void* b))
{
    for(int i = n-1/2; i > -1; --i)
        heapify(arr, i, n, size, compare);
    return;
}

void heap_increase_key(void* arr, int i, int size, int
(*compare)(const void* a, const void* b), void* newkey)
{
	char* a = (char*) arr;
	char* key = (char*) newkey;
	while((i > 0) && (compare(a+((i-1)/2)*size, key) < 0))
	{	
		swap(a+i*size, a+((i-1)/2)*size, size);
		i = (i-1)/2;
	}
	swap(a+i*size, key, size);
	return;
}

void heap_insert(void* arr, int* n, int size, int (*compare)(const
void* a, const void* b), void* newkey)
{
	if ((*n + 1) == MAX_SIZE)
	{
		printf("Limit has been reached. New element is not added\n");
		return;
	}
	++(*n);
	heap_increase_key(arr, *n-1, size, compare, newkey);
}

void* heap_extract_max(void* arr, int* n, int size, int (*compare)(const void* a, const void* b))
{
	if ((*n) == 0)
	{
		printf("There's no elements\n");
		return 0;
	}
	char* a = (char*) arr;
	swap(a, a+(--(*n))*size, size);
	heapify(arr, 0, *n, size, compare);
	return a+(*n)*size;
}

int main()
{
	int n = 0;
	struct element* a = (struct element*) malloc(MAX_SIZE*sizeof(struct
element));
	char* com = (char*) malloc(256*sizeof(char));
	while (1)
	{
		printf("Insert com\n");
		scanf("%s", com);
		if (strcmp(com, "insert\0") == 0)
		{
			printf("Insert value\n");
			struct element value;
			scanf("%d", &(value.key));
			scanf("%d", &(value.priority));
			heap_insert(a, &n, sizeof(struct element),
compare_priority, &value);
		}
		if (strcmp(com, "del\0") == 0)
			heap_extract_max(a, &n, sizeof(struct element), compare_priority);
		if (strcmp(com, "peek\0") == 0)
			if (a)
			{
				printf("max (%d, %d)\n", a->key, a->priority);
			}
		if (strcmp(com, "size\0") == 0)
			printf("size %d\n", n);
		if (strcmp(com, "exit\0") == 0)
			break;
		for(int i = 0; i < n; ++i)
			printf("(%d, %d) ", a[i].key, a[i].priority);
		printf("\n---\n");
	}
	printf("--- start free array ---\n");
	free(a);
	printf("--- free array successful ---\n");
	free(com);
	printf("exit\n");
	return 0;
}
