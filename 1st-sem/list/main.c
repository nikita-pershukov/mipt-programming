#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_NULL(void* ukaz)
{
    if (ukaz == NULL)
        exit(666);
}

struct Element
{
    int Value;
    struct Element* Next;
	struct Element *Prev;
};

struct List
{
    struct Element* Head;
    struct Element* Tail;
};

int list_add_head(struct List* a, int v)
{
    struct Element* newElement = (struct Element*) malloc(sizeof(struct Element));
    check_NULL(newElement);
    newElement->Value = v;
    newElement->Next = a->Head;
	newElement->Prev = NULL;
	if (a->Head != NULL)
		(a->Head)->Prev = newElement;
    a->Head = newElement;
	if (a->Tail == NULL)
		a->Tail = newElement;
    return 1;
}

int list_del_head(struct List* a, struct Element* res)
{
    if (a->Head == NULL)
	{
		printf("There's no elements\n");
		return 0;
	}
    struct Element* del = a->Head;
    a->Head = a->Head->Next;
	if (a->Head != NULL)
		a->Head->Prev = NULL;
    *res = *del;
    free(del);
    if (a->Head == NULL)
        a->Tail = NULL;
    return 1;
}

int list_add_tail(struct List* a, int v)
{
    struct Element* newElement = (struct Element*) malloc(sizeof(struct Element));
    check_NULL(newElement);
    newElement->Value = v;
    newElement->Next = NULL;
	newElement->Prev = a->Tail;
    if (a->Tail != NULL)
    {
        (a->Tail)->Next = newElement;
    }
	a->Tail = newElement;
	if (a->Head == NULL)
		a->Head = newElement;
    return 1;
}

int list_del_tail(struct List* a, struct Element* res)
{
    if (a->Tail == NULL)
	{
		printf("There's no elements\n");
		return 0;
	}
    struct Element* del = a->Tail;
    a->Tail = a->Tail->Prev;
	if (a->Tail != NULL)
		a->Tail->Next = NULL;
    *res = *del;
    free(del);
    if (a->Tail == NULL)
        a->Head = NULL;
    return 1;
}

int reverse(struct List* a)
{
    if (a->Head == NULL)
        return 0;
    if (a->Head == a->Tail)
        return 1;
    struct Element* pointer = a->Head;
    struct Element* draft;
    while(pointer != NULL)
    {
        draft = pointer->Next;
        pointer->Next = pointer->Prev;
        pointer->Prev = draft;
        pointer = pointer->Prev;
    }
    pointer = a->Head;
    a->Head = a->Tail;
    a->Tail = pointer;
    return 1;
}

void list_new(struct List** a)
{
    struct List* newList = (struct List*) malloc(sizeof(struct List));
    check_NULL(newList);
    newList->Head = NULL;
    newList->Tail = NULL;
    *a = newList;
    return;
}

void list_delete(struct List* a)
{
    struct Element* pointer = a->Head;
    struct Element* del;
    while(pointer != NULL)
    {
        del = pointer;
        pointer = pointer->Next;
        free(del);
    }
    printf("--- start free array ---\n");
	free(a);
	printf("--- free array successful ---\n");
    return;
}

int main(void)
{
    int n;
    struct List* a;
    list_new(&a);
    char* com = (char*) malloc(256*sizeof(char));
	while(1)
	{
		scanf("%s", com);
		if (strcmp(com, "add_head") == 0)
		{
        	printf("%s\n", com);
        	int draft;
        	getchar();
        	scanf("%d", &draft);
        	list_add_head(a, draft);
    	}
    	if (strcmp(com, "add_tail") == 0)
    	{
        	printf("%s\n", com);
        	int draft;
        	getchar();
        	scanf("%d", &draft);
        	list_add_tail(a, draft);
    	}
    	if (strcmp(com, "del_head") == 0)
    	{
            struct Element* del = (struct Element*) malloc(sizeof(struct
            Element));
      	    list_del_head(a, del);
     	    printf("%s %d\n", com, del->Value);
            free(del);
        }
    	if (strcmp(com, "del_tail") == 0)
    	{
            struct Element* del = (struct Element*) malloc(sizeof(struct
            Element));
      	    list_del_tail(a, del);
     	    printf("%s %d\n", com, del->Value);
            free(del);
    	}
        if (strcmp(com, "reverse") == 0)
		{
            reverse(a);
        }
		if (strcmp(com, "exit") == 0)
		{
			break;
		}
    	for(struct Element* ukaz = a->Head; ukaz != NULL; ukaz = ukaz->Next)
    	    printf("%d ", ukaz->Value);
    	printf("\n");
    }
	list_delete(a);
    free(com);
	printf("exit\n");
	return 0;
}

