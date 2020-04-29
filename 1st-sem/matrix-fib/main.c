#include <stdio.h>
#include <stdlib.h>

void check(void * ukaz)
{
    if (ukaz == NULL)
        exit(666);
    return;
}

int** matrix_st(int matrix[2][2])
{
    int res_matrix [2][2];
    for (int i = 0; i < size; ++i)
    {
        res_matrix[i] = (int *) malloc (size*sizeof(int));
        check(res_matrix[i]);
        for(int j = 0; j < size; ++j)
        {
            res_matrix[i][j] = 0;
            for(int k = 0; k < size; ++k)
            {
                res_matrix[i][j] += input_matrix[i][k]*input_matrix[k][j];
            }
        }
    }
    return res_matrix;
}

int main(void)
{
    size_t size;
    int st = 0;
    scanf("%d", &st);
    scanf("%d", &size);
    int matrix [2][2];
    for (int i = 0; i < size; ++i)
        for(int j = 0; j < size; ++j)
            scanf("%d", &matrix[i][j]);
    for(int i = 0; i < st; ++st)
        matrix_st(matrix);
    printf("%d\n", matrix[0][0]);
    return 0;
}

