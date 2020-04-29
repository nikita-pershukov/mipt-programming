#include <stdio.h>

void sort(int* arr, size_t n)
{
    for (int i = 1; i < n; ++i)
    {
        int draft = arr[i];
        for (int j = i - 1; j >= 0; --j)
        {
            if (arr[j] < draft)
                break;
            arr[j + 1] = arr[j];
            arr[j] = draft;
        }
        for(int j = 0; j < n; ++j)
            printf("%d_%d\n", j, arr[j]);
        if (i < n-1)
            printf("--------- Processing %d/%d ---------\n", i, n-1);
    }
}

int main(void)
{
    size_t n = rand()%100;
    int* arr = (int*) malloc (n*sizeof(int));
    if (arr == NULL)
        exit(666);
    for(int i = 0; i < n; ++i)
    {
        arr[i] = rand() % 1000000;
        printf("%d_%d\n", i, arr[i]);
    }
    printf("--------- Sorting started ---------\n");
    sort(arr, n);
    printf("--------- Array is sorted ---------\n");
    for(int i = 0; i < n; ++i)
        printf("%d_%d\n", i, arr[i]);
    return 0;
}

