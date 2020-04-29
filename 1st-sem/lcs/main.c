#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1024

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
    char* a = (char*) malloc(MAX_SIZE*sizeof(char));
    check_NULL(a);
    char* b = (char*) malloc(MAX_SIZE*sizeof(char));
    check_NULL(b);
    scanf("%s", a);
    scanf("%s", b);
    int n = strlen(a);
    int m = strlen(b);
    int** res = (int**) malloc(n*sizeof(int*));
    check_NULL(res);
    for(int i = 0; i < n; ++i)
    {
        res[i] = (int*) malloc(m*sizeof(int));
        for(int j = 0; j < m; ++j)
        {
            if (a[i] == b[j])
            {
                res[i][j] = 1;
                if ((i > 0) && (j > 0))
                    res[i][j] += res[i-1][j-1];
            }
            else
            {
                res[i][j] = 0;
                if ((i > 0) && (res[i-1][j] > res[i][j]))
                    res[i][j] = res[i-1][j];
                if ((j > 0) && (res[i][j-1] > res[i][j]))
                    res[i][j] = res[i][j-1];
            }
        }
    }
    int* seq = (int*) malloc(n*sizeof(int));
    check_NULL(seq);
    int count = 0;
    int i = n-1;
    int j = m -1;
    while((i > -1) && (j > -1))
    {
        if (a[i] == b[j])
        {
            seq[count++] = a[i];
            --i;
            --j;
        }
        else
        {
            int max = 0;
            if ((i > 0) && (res[i-1][j] > max))
                max = res[i-1][j];
            if ((j > 0) && (res[i][j-1] > max))
                max = res[i][j];
            if ((i > 0) && (max == res[i-1][j]))
                --i;
            else    
                if ((j > 0) && (max == res[i][j-1]))
                    --j;
        }
    }
    for(i = count-1; i > -1; --i)
        printf("%c", seq[i]);
    printf("\n");
    return 0;
}
