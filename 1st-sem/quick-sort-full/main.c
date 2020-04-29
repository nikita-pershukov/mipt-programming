#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

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

void heapify(void* arr, int i, int n, int size, int (*compare)(const void* a, const void* b))
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

void buildheap(void* arr, int n, int size, int (*compare)(const void* a, const void* b))
{
	for(int i = n-1/2; i > -1; --i)
		heapify(arr, i, n, size, compare);
	return;
}

void heapsort_insert(void* arr, int n, int size, int (*compare)(const
void* a, const void* b), int insert)
{
	if (n == 1)
		return;
	char* a = (char*) arr;
	if (n > insert)
	{
		buildheap(a, n, size, compare);
		for(int i = n-1; i > (insert-1); --i)
		{
			swap(a, a+i*size, size);
			heapify(a, 0, i, size, compare);
		}
	}
	if (n < insert)
		insert = n;
	insertsort(a, insert, size, compare);
	return;
}

void quicksort(void* arr, int first, int last, int size, int (*compare)(const void* a, const void* b))
{
	if (last == 0)
		return;
	char* a = (char*) arr;
	int i = first;
	int j = last;
	int base = (first + last) / 2;
	while(i <= j)
	{
		while (compare(a+i*size, a+base*size) < 0 )
			i++;
		while (compare(a+j*size, a+base*size) > 0)
			j--;
		if(i <= j)
		{
			if (i < j)
			{
				swap(a+i*size, a+j*size, size);
				int newbase = base;
				if (i == base)
					newbase = j;
				if (j == base)
					newbase = i;
				base = newbase;
			}
			i++;
			j--;
		}
	}
	if (i < last)
		quicksort(a, i, last, size, compare);
	if (first < j)
		quicksort(a, first, j, size, compare);
	return;
}

void quicksort_med(void* arr, int first, int last, int size, int (*compare)(const void* a, const void* b))
{
	if (last == 0)
		return;
	char* a = (char*) arr;
	int i = first;
	int j = last;
	int min = first;
	int max = last;
	int base = (first + last) / 2;
	if (compare(a+min*size, a+max*size) > 0)
		swap_int(&min, &max);
	if (compare(a+base*size, a+min*size) < 0)
		swap_int(&base, &min);
	if (compare(a+base*size, a+max*size) > 0)
		swap_int(&base, &max);
	while(i <= j)
	{
		while (compare(a+i*size, a+base*size) < 0)
			i++;
		while (compare(a+j*size, a+base*size) > 0)
			j--;
		if(i <= j)
		{
			if (i < j)
			{
				swap(a+i*size, a+j*size, size);
				int newbase = base;
				if (i == base)
					newbase = j;
				if (j == base)
					newbase = i;
				base = newbase;
			}
			i++;
			j--;
		}
	}
	if (i < last)
		quicksort_med(a, i, last, size, compare);
	if (first < j)
		quicksort_med(a, first, j, size, compare);
	return;
}

void quicksort_rand(void* arr, int first, int last, int size, int
(*compare)(const void* a, const void* b))
{
	if (last == 0)
		return;
	char* a = (char*) arr;
	int i = first;
	int j = last;
	int base = first + rand()%(last-first);
	while(i <= j)
	{
		while (compare(a+i*size, a+base*size) < 0)
			i++;
		while (compare(a+j*size, a+base*size) > 0)
			j--;
		if(i <= j)
		{
			if (i < j)
			{
				swap(a+i*size, a+j*size, size);
				int newbase = base;
				if (i == base)
					newbase = j;
				if (j == base)
					newbase = i;
				base = newbase;
			}
			i++;
			j--;
		}
	}
	if (i < last)
		quicksort_rand(a, i, last, size, compare);
	if (first < j)
		quicksort_rand(a, first, j, size, compare);
	return;
}

void quicksort_med_rand(void* arr, int first, int last, int size, int
(*compare)(const void* a, const void* b))
{
	if (last == 0)
		return;
	char* a = (char*) arr;
	int i = first;
	int j = last;
	int min = first + rand()%(last-first);
	int max = first + rand()%(last-first);
	int base = first + rand()%(last-first);
	if (compare(a+min*size, a+max*size) > 0)
		swap_int(&min, &max);
	if (compare(a+base*size, a+min*size) < 0)
		swap_int(&base, &min);
	if (compare(a+base*size, a+max*size) > 0)
		swap_int(&base, &max);
	while(i <= j)
	{
		while (compare(a+i*size, a+base*size) < 0)
			i++;
		while (compare(a+j*size, a+base*size) > 0)
			j--;
		if(i <= j)
		{
			if (i < j)
			{
				swap(a+i*size, a+j*size, size);
				int newbase = base;
				if (i == base)
					newbase = j;
				if (j == base)
					newbase = i;
				base = newbase;
			}
			i++;
			j--;
		}
	}
	if (i < last)
		quicksort_med_rand(a, i, last, size, compare);
	if (first < j)
		quicksort_med_rand(a, first, j, size, compare);
	return;
}

void quicksort_med_rand_while(void* arr, int first, int last, int size, int (*compare)(const void* a, const void* b))
{
	if (last == 0)
		return;
	char* a = (char*) arr;
	while(first < last)
	{
		int i = first;
		int j = last;
		int min = first + rand()%(last-first);
		int max = first + rand()%(last-first);
		int base = first + rand()%(last-first);
		if (compare(a+min*size, a+max*size) > 0)
			swap_int(&min, &max);
		if (compare(a+base*size, a+min*size) < 0)
			swap_int(&base, &min);
		if (compare(a+base*size, a+max*size) > 0)
			swap_int(&base, &max);
		while(i <= j)
		{
			while (compare(a+i*size, a+base*size) < 0)
				i++;
			while (compare(a+j*size, a+base*size) > 0)
				j--;
			if(i <= j)
			{
				if (i < j)
				{
					swap(a+i*size, a+j*size, size);
					int newbase = base;
					if (i == base)
						newbase = j;
					if (j == base)
						newbase = i;
					base = newbase;
				}
				i++;
				j--;
			}
		}
		if ((last - first) == 1)
			return;
		if ((i <= last) && (j >= first))
		{
			if ((last - i) > (j - first))
			{
				quicksort_med_rand_while(a, first, j, size, compare);
				first = i;
				continue;
			}
			else
			{
				quicksort_med_rand_while(a, i, last, size, compare);
				last = j;
				continue;
			}
		}
	}
	return;
}

void quicksort_med_rand_while_heap_insert(void* arr, int first, int
last, int size, int (*compare)(const void* a, const void* b), int heap, int insert)
{
	if (last == 0)
		return;
	char* a = (char*) arr;
	while((first < last) && ((last - first) > heap))
	{
		int i = first;
		int j = last;
		int min = first + rand()%(last-first);
		int max = first + rand()%(last-first);
		int base = first + rand()%(last-first);
		if (compare(a+min*size, a+max*size) > 0)
			swap_int(&min, &max);
		if (compare(a+base*size, a+min*size) < 0)
			swap_int(&base, &min);
		if (compare(a+base*size, a+max*size) > 0)
			swap_int(&base, &max);
		while(i <= j)
		{
			while (compare(a+i*size, a+base*size) < 0)
				i++;
			while (compare(a+j*size, a+base*size) > 0)
				j--;
			if(i <= j)
			{
				if (i < j)
				{
					swap(a+i*size, a+j*size, size);
					int newbase = base;
					if (i == base)
						newbase = j;
					if (j == base)
						newbase = i;
					base = newbase;
				}
				i++;
				j--;
			}
		}
		if ((last - first) == 1)
			return;
		if ((i <= last) && (j >= first))
		{
			if ((last - i) > (j - first))
			{
				quicksort_med_rand_while(a, first, j, size, compare);
				first = i;
				continue;
			}
			else
			{
				quicksort_med_rand_while(a, i, last, size, compare);
				last = j;
				continue;
			}
		}
	}
	if (first < last)
		heapsort_insert(a+first, last-first+1, size, compare, insert); 
	return;
}

int main()
{
	srand(time(NULL));

	int n_int;
	printf("int [n_int]\n");

	scanf("%d", &n_int);
//	n_int = 1000000;

	int* a_int = (int*) malloc(n_int*sizeof(int));
	check_NULL(a_int);
	int* b_int = (int*) malloc(n_int*sizeof(int));
	check_NULL(b_int);
	for(int i = 0; i < n_int; ++i)
		scanf("%d", &(a_int[i]));
//		a_int[i] = rand()%1000;
	memmove(b_int, a_int, n_int*sizeof(int));
	int start = clock();
	quicksort(a_int, 0, n_int-1, sizeof(int), compare_int);
	int end = clock();
	for(int i = 0; i < n_int; ++i)
		printf("%d ", a_int[i]);
	printf("\nint %d quicksort %.6lf\n",
n_int, (end-start+0.0)/CLOCKS_PER_SEC);
	printf("\n");
	memmove(a_int, b_int, n_int*sizeof(int));
	start = clock();
	quicksort_med(a_int, 0, n_int-1,
sizeof(int), compare_int);
	end = clock();
	for(int i = 0; i < n_int; ++i)
		printf("%d ", a_int[i]);
	printf("\nint %d quicksort_med %.6lf\n",
n_int, (end-start+0.0)/CLOCKS_PER_SEC);
	printf("\n");
	memmove(a_int, b_int, n_int*sizeof(int));
	start = clock();
	quicksort_rand(a_int, 0, n_int-1,
sizeof(int), compare_int);
	end = clock();
	for(int i = 0; i < n_int; ++i)
		printf("%d ", a_int[i]);
	printf("\nint %d quicksort_rand %.6lf\n",
n_int, (end-start+0.0)/CLOCKS_PER_SEC);
	printf("\n");
	memmove(a_int, b_int, n_int*sizeof(int));
	start = clock();
	quicksort_med_rand(a_int, 0, n_int-1,
sizeof(int), compare_int);
	end = clock();
	for(int i = 0; i < n_int; ++i)
		printf("%d ", a_int[i]);
	printf("\nint %d quicksort_med_rand %.6lf\n",
n_int, (end-start+0.0)/CLOCKS_PER_SEC);
	printf("\n");
	memmove(a_int, b_int, n_int*sizeof(int));
	start = clock();
	quicksort_med_rand_while(a_int, 0, n_int-1,
sizeof(int), compare_int);
	end = clock();
	for(int i = 0; i < n_int; ++i)
		printf("%d ", a_int[i]);
	printf("\nint %d quicksort_med_rand_while %.6lf\n",
n_int, (end-start+0.0)/CLOCKS_PER_SEC);
	printf("\n");
	memmove(a_int, b_int, n_int*sizeof(int));
	start = clock();
	quicksort_med_rand_while_heap_insert(a_int, 0, n_int-1,
sizeof(int), compare_int, round(log(n_int)), 16);
	end = clock();
	for(int i = 0; i < n_int; ++i)
		printf("%d ", a_int[i]);
	printf("\nint %d quicksort_med_rand_while_heap_insert %.6lf\n",
n_int, (end-start+0.0)/CLOCKS_PER_SEC);
	printf("\n\n---------\n");
	free(a_int);
	free(b_int);

	

	int n_double;
	printf("double [n_double]\n");
	scanf("%d", &n_double);
	double* a_double = (double*) malloc(n_double*sizeof(double));
	check_NULL(a_double);
	double* b_double = (double*) malloc(n_double*sizeof(double));
	check_NULL(b_double);
	for(int i = 0; i < n_double; ++i)
		scanf("%lf", &(a_double[i]));
	memmove(b_double, a_double, n_double*sizeof(double));
	start = clock();
	quicksort(a_double, 0, n_double-1, sizeof(double),
compare_double);
	end = clock();
	for(int i = 0; i < n_double; ++i)
		printf("%lf ", a_double[i]);
	printf("\ndouble %d quicksort %.6lf\n",
n_double, (end-start+0.0)/CLOCKS_PER_SEC);
	printf("\n");
	memmove(a_double, b_double, n_double*sizeof(double));
	start = clock();
	quicksort_med(a_double, 0, n_double-1, sizeof(double),
compare_double);
	end = clock();
	for(int i = 0; i < n_double; ++i)
		printf("%lf ", a_double[i]);
	printf("\ndouble %d quicksort_med %.6lf\n",
n_double, (end-start+0.0)/CLOCKS_PER_SEC);
	printf("\n");
	memmove(a_double, b_double, n_double*sizeof(double));
	start = clock();
	quicksort_rand(a_double, 0, n_double-1, sizeof(double),
compare_double);
	end = clock();
	for(int i = 0; i < n_double; ++i)
		printf("%lf ", a_double[i]);
	printf("\ndouble %d quicksort_rand %.6lf\n",
n_double, (end-start+0.0)/CLOCKS_PER_SEC);
	printf("\n");
	memmove(a_double, b_double, n_double*sizeof(double));
	start = clock();
	quicksort_med_rand(a_double, 0, n_double-1, sizeof(double),
compare_double);
	end = clock();
	for(int i = 0; i < n_double; ++i)
		printf("%lf ", a_double[i]);
	printf("\ndouble %d quicksort_med_rand %.6lf\n",
n_double, (end-start+0.0)/CLOCKS_PER_SEC);
	printf("\n");
	memmove(a_double, b_double, n_double*sizeof(double));
	start = clock();
	quicksort_med_rand_while(a_double, 0, n_double-1, sizeof(double),
compare_double);
	end = clock();
	for(int i = 0; i < n_double; ++i)
		printf("%lf ", a_double[i]);
	printf("\ndouble %d quicksort_med_rand_while %.6lf\n",
n_double, (end-start+0.0)/CLOCKS_PER_SEC);
	printf("\n");
	memmove(a_double, b_double, n_double*sizeof(double));
	start = clock();
	quicksort_med_rand_while_heap_insert(a_double, 0, n_double-1, sizeof(double),
compare_double, round(log(n_double)), 16);
	end = clock();
	for(int i = 0; i < n_double; ++i)
		printf("%lf ", a_double[i]);
	printf("\ndouble %d quicksort_med_rand_while_heap_insert %.6lf\n",
n_double, (end-start+0.0)/CLOCKS_PER_SEC);
	printf("\n\n---------\n");
	free(a_double);
	free(b_double);



	int n_str, size_str;
	printf("srt [n_str, size]\n");
	scanf("%d", &n_str);
	scanf("%d", &size_str);
	char** a_str = (char**) malloc(n_str*sizeof(char*));
	check_NULL(a_str);
	char** b_str = (char**) malloc(n_str*sizeof(char*));
	check_NULL(b_str);
	for(int i = 0; i < n_str; ++i)
	{
		a_str[i] = (char*) malloc((size_str+1)*sizeof(char));
		check_NULL(a_str[i]);
		b_str[i] = (char*) malloc((size_str+1)*sizeof(char));
		check_NULL(b_str[i]);
		scanf("%s", a_str[i]);
		printf("%s ", a_str[i]);
		memmove(b_str[i], a_str[i], size_str*sizeof(char));
	}
	printf("\n");
	start = clock();
	quicksort(a_str, 0, n_str-1,
sizeof(char*), compare_str);
	end = clock();
	for(int i = 0; i < n_str; ++i)
		printf("%s ", a_str[i]);
	printf("\nstr %d quicksort %.6lf\n",
n_str, (end-start+0.0)/CLOCKS_PER_SEC);
	printf("\n");	
	for(int i = 0; i < n_str; ++i)
		memmove(a_str[i], b_str[i], size_str*sizeof(char));
	start = clock();
	quicksort_med(a_str, 0, n_str-1,
sizeof(char*), compare_str);
	end = clock();
	for(int i = 0; i < n_str; ++i)
		printf("%s ", a_str[i]);
	printf("\nstr %d quicksort_med %.6lf\n",
n_str, (end-start+0.0)/CLOCKS_PER_SEC);
	printf("\n");
	for(int i = 0; i < n_str; ++i)
		memmove(a_str[i], b_str[i], size_str*sizeof(char));
	start = clock();
	quicksort_rand(a_str, 0, n_str-1,
sizeof(char*), compare_str);
	end = clock();
	for(int i = 0; i < n_str; ++i)
		printf("%s ", a_str[i]);
	printf("\nstr %d quicksort_rand %.6lf\n",
n_str, (end-start+0.0)/CLOCKS_PER_SEC);
	printf("\n");
	for(int i = 0; i < n_str; ++i)
		memmove(a_str[i], b_str[i], size_str*sizeof(char));
	start = clock();
	quicksort_med_rand(a_str, 0, n_str-1,
sizeof(char*), compare_str);
	end = clock();
	for(int i = 0; i < n_str; ++i)
		printf("%s ", a_str[i]);
	printf("\nstr %d quicksort_med_rand %.6lf\n",
n_str, (end-start+0.0)/CLOCKS_PER_SEC);
	printf("\n");
	for(int i = 0; i < n_str; ++i)
		memmove(a_str[i], b_str[i], size_str*sizeof(char));
	start = clock();
	quicksort_med_rand_while(a_str, 0, n_str-1,
sizeof(char*), compare_str);
	end = clock();
	for(int i = 0; i < n_str; ++i)
		printf("%s ", a_str[i]);
	printf("\nstr %d quicksort_med_rand_while %.6lf\n",
n_str, (end-start+0.0)/CLOCKS_PER_SEC);
	printf("\n");
	for(int i = 0; i < n_str; ++i)
		memmove(a_str[i], b_str[i], size_str*sizeof(char));
	start = clock();
	quicksort_med_rand_while_heap_insert(a_str, 0, n_str-1,
sizeof(char*), compare_str, round(log(n_str)), 16);
	end = clock();
	for(int i = 0; i < n_str; ++i)
		printf("%s ", a_str[i]);
	printf("\nstr %d quicksort_med_rand_while_heap_insert %.6lf\n",
n_str, (end-start+0.0)/CLOCKS_PER_SEC);
	printf("\n\n---------\n");
	for(int i = 0; i < n_str; i++)
	{
		free(a_str[i]);
		free(b_str[i]);
	}
	free(a_str);
	free(b_str);

	return 0;
}
