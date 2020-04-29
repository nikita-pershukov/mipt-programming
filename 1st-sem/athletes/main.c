#include <stdio.h>
#include <stdlib.h>

struct Athlete
{
    int weight;
    int strength;
};

void check_NULL(void* pointer)
{
	if (pointer == NULL)
	{
		printf("Erroe\n");
		exit(666);
	}
	return;
}

int compare_athlete(const void* a, const void* b)
{
    struct Athlete a_a = *((struct Athlete*)a);
    struct Athlete b_a = *((struct Athlete*)b);
    if (a_a.weight > b_a.weight)
        return 1;
    if (a_a.weight < b_a.weight)
        return -1;
    if (a_a.strength > b_a.strength)
        return 1;
    if (a_a.strength < b_a.strength)
        return -1;
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    struct Athlete* a = (struct Athlete*) malloc(n*sizeof(struct
    Athlete));
    check_NULL(a);
    struct Athlete* b = (struct Athlete*) malloc(n*sizeof(struct
    Athlete));
    check_NULL(b);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &(a[i].weight));
        scanf("%d", &(a[i].strength));
    }
    qsort(a, n, sizeof(struct Athlete), compare_athlete);
    int weight = a[0].weight;
    b[0] = a[0];
    int i = 1;
    int count = 1;
    while(i < n)
    {
        if (a[i].strength >= weight)
        {
            b[count++] = a[i];
            weight += a[i].weight;
        }
        i++;
    }
    for(i = 0; i < count; ++i)
        printf("%d %d | ", b[i].weight, b[i].strength);
    printf("\n");
    free(a);
    free(b);
    return 0;
}
