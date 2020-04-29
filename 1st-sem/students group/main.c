#include <stdio.h>
#include <stdlib.h>

void check_NULL(void* pointer)
{
	if (pointer == NULL)
	{
		printf("Erroe\n");
		exit(666);
	}
	return;
}

struct student
{
    int card;
    char name[32];
    int mark;
};

struct marks
{
    struct student* a;
    int size;
};

int main()
{
    int n;
    struct marks* arr = (struct marks*) malloc(4*sizeof(struct
    marks));
    check_NULL(arr);
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        arr[i].size = 0;
        arr[i].a = (struct student*) malloc(n*sizeof(struct student));
    }
    for(int i = 0; i < n; ++i)
    {
        struct student draft;
        scanf("%d", &(draft.card));
        scanf("%s", draft.name);
        scanf("%d", &(draft.mark));
        arr[draft.mark-2].a[arr[draft.mark-2].size++] = draft;
    }
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < arr[i].size; ++j)
        {
            printf("%d %s %d\n", arr[i].a[j].card, arr[i].a[j].name,
            arr[i].a[j].mark);
        }
        free(arr[i].a);
    }        
    free(arr);
    return 0;
}
