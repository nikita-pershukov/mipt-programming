#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
struct slist
{ 
    int val;
    struct slist *next; 
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

struct slist* my_radixsort(struct slist *L, int t) 
{
    int i, j, d, m=1;
    struct slist *temp;
    struct slist *head[10];
    struct slist *tail[10]; 
    for(j = 1; j <= t; ++j) 
    { 
        for(i=0; i < 10; ++i)
        {
            head[i] = NULL;
            tail[i] = NULL;
        }
        while(L != NULL) 
        {
            d = (L->val/m)%10;
            temp = L;
            L = L->next;
            temp->next = NULL;
            if (head[d]!= NULL)
            {
                tail[d]->next = temp;
                tail[d] = temp;
            }
            else
            {
                head[d] = temp;
                tail[d] = temp;
            }
        }
        d = 0;
        while(head[d] == NULL)
            ++d;
        L = head[d];
        temp = tail[d];
        ++d;
        while(d < 10)
        {
            if (head[d] != NULL)
            {
                temp->next = head[d];
                temp = tail[d];
            }
            ++d;
        }
        m *= 10;
    }
    return L;
}
 
int main()
{
    srand(time(NULL));
    int n[20];
    int i;
    int max = -1;
    int t = 0;
    struct slist* start = NULL;
    struct slist* end = NULL;
    struct slist* temp;
    for (i = 0; i < 20; ++i)
    {
        n[i] = rand()%100;
    }
    for (i = 0; i < 20; ++i)
    {
        if (n[i] > max)
            max = n[i];
        temp = (struct slist*) malloc(sizeof(struct slist));
	    check_NULL(temp);
        temp->val = n[i];
        temp->next = NULL;
        if (start != NULL)
        {
            end->next = temp;
            end = temp;
        }
        else
        {
            start = temp;
            end = temp;
        }
    }
    while(max > 0)
    {
        t=t+1;
        max=max/10;    
    } 
    start = my_radixsort(start, t);
    temp = start;
    for (i=0; i<20; i++)
    {
	struct slist* del = temp;
        printf("%d ", temp->val);
        temp = temp->next;
	free(del);
    }
    printf("\n");
    return 0;
}
