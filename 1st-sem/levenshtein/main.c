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

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

int main()
{
	char *s1 = (char*) malloc (MAX_SIZE*sizeof(char));
	check_NULL(s1);
    char *s2 = (char*) malloc (MAX_SIZE*sizeof(char));
	check_NULL(s2);
    scanf("%s", s1);
    scanf("%s", s2);
    int n1 = strlen(s1);
	int n2 = strlen(s2);
	int **a = (int**) malloc((n2 + 1)*sizeof(int*));
    check_NULL(a);
	for (int i = 0; i <= n2; i++)
	{
		a[i] = (int*) malloc(sizeof(int)*(n1 + 1));
        check_NULL(a[i]);
	}
	for (int i = 0; i <= n2; i++)
	{
		a[i][0] = i;
	}
	for (int i = 1; i <= n1; i++)
	{
		a[0][i] = i;
	}
	for (int i = 1; i <= n2; i++)
	{
		for (int j = 1; j <= n1; j++)
		{
			if (s2[i - 1] == s1[j - 1])
			{
				a[i][j] = a[i - 1][j - 1];
			}
			else
			{
				a[i][j] = min(min(a[i - 1][j - 1], a[i - 1][j]), a[i][j - 1]) + 1;
			}
		}
	}
	printf("%d\n", a[n2][n1]);

	for (int i = 0; i <= n2; i++) {
		free(a[i]);
	}

	free(a);
	free(s1);
	free(s2);

	return 0;
}
