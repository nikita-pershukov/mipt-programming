#include "stdio.h"
#include "stdlib.h"

void check_NULL(void* pointer)
{
	if (pointer == NULL)
	{
		printf("Erroe\n");
		exit(666);
	}
	return;
}

int main()
{
    int i, j, n;
    scanf("%d",&n);
    int *array = (int*)malloc(sizeof(int)*(n+1));
    check_NULL(array);
    int *arr_length = (int*)malloc(sizeof(int)*(n+1));
    check_NULL(arr_length);
    int *arr_ancestor = (int*)malloc(sizeof(int)*(n+1));
    check_NULL(arr_ancestor);
    for (i = 1; i<= n; ++i)
    {
        scanf("%d", &(array[i]));
        arr_length[i] = 1;
        arr_ancestor[i] = 0;
    }
    int leng_max = 0;
    int index = 0;
    for (i = 1; i <= n-1; ++i)
        for (j = i+1; j <= n; ++j)
        {
            if (array[i] < array[j])
            {
                if (arr_length[i] >= arr_length[j])
                {
                    arr_length[j] = arr_length[i] + 1;
                    arr_ancestor[j] = i;
                    if (arr_length[j] > leng_max) 
                    {
                        leng_max = arr_length[j];
                        index = j;
                    }
                }
            }
        }
    j = 1;
    i = index;
    while(i > 0)
    {
        arr_length[j++] = array[arr_ancestor[i]];
        i = arr_ancestor[i];    
    }
    for (i = leng_max - 1; i > 0; --i)
        printf("%d ", arr_length[i]);
    printf("%d\n", array[index]);
    return 0;
}


