#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char name[32];
    int mark;
};

void swap(struct student* student1, struct student* student2)
{
    struct student draft = *student1;
    *student1 = *student2;
    *student2 = draft;
    return;
}

int ind_bin_search(struct student* arr, size_t n, char* name)
{
    if (!((strcmp(name, arr[0].name) < 0)||(strcmp(name, arr[n-1].name) > 0)||!n))
    {
        size_t first = 0;
        size_t last = n;
        size_t mid = last/2;
        while (first < last)
        {
            if (strcmp(arr[mid].name, name) >= 0)
                last = mid;
            else
                first = mid+1;
            mid = first+(last-first)/2;
        }
        if (strcmp(name, arr[last].name) == 0)
            return last;
    }
    return -1;
}

int main(void)
{
    size_t n;
    scanf("%zd", &n);
    struct student* arr = (struct student*) malloc(n*sizeof(struct student));
    if (arr == NULL)
        exit(666);
    for(int i = 0; i < n; ++i)
        scanf("%s %d", &arr[i].name, &arr[i].mark);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n-i-1; ++j)
            if(strcmp(arr[j].name, arr[j+1].name) > 0)
                swap(&arr[j], &arr[j+1]);
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; ++i)
    {
        char draft[32];
        scanf("%s", &draft);
        int ind = ind_bin_search(arr, n, draft);
        if (ind != -1)
            printf("%s_%d\n", arr[ind].name, arr[ind].mark);
        else
            printf("%s_not_found\n", draft);
    }
    return 0;
}

