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
};

struct List
{
    struct Element* Head;
    struct Element* Tail;
};

void list_add_head(struct List* a, int v)
{
    struct Element* newElement = (struct Element*) malloc(sizeof(struct Element));
    check_NULL(newElement);
    newElement->Value = v;
    newElement->Next = a->Head;
    a->Head = newElement;
    return;
}

void list_del_head(struct List* a)
{
    check_NULL(a->Head);
    struct Element* del = a->Head;
    a->Head = a->Head->Next;
    free(del);
    if (a->Head == NULL)
        a->Tail = NULL;
    return;
}

void list_add_tail(struct List* a, int v)
{
    struct Element* newElement = (struct Element*) malloc(sizeof(struct Element));
    check_NULL(newElement);
    newElement->Value = v;
    newElement->Next = NULL;
    if (a->Head == NULL)
    {
        a->Head = newElement;
        a->Tail = newElement;
    }
    else
    {
        a->Tail->Next = newElement;
        a->Tail = newElement;
    }
    return;
}

void list_del_tail(struct List* a)
{
    struct Element* ukaz = a->Head;
    check_NULL(ukaz);
    while(!(ukaz->Next == a->Tail))
        ukaz = ukaz->Next;
    check_NULL(ukaz);
    a->Tail = ukaz;
    free(ukaz->Next);
    ukaz->Next = NULL;
    return;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    struct List* a = (struct List*) malloc(sizeof(struct List));
    check_NULL(a);
    a->Head = NULL;
    a->Tail = NULL;
    for(int i = 0; i < n; ++i)
    {
        int draft;
        scanf("%d", &draft);
        list_add_tail(a, draft);
    }
    for(struct Element* ukaz = a->Head; ukaz != NULL; ukaz = ukaz->Next)
        printf("%d ", ukaz->Value);
    printf("\n");
    char command[8];
    scanf("%s", &command);
    if (strcmp(command, "add_head") == 0)
    {
        printf("%s\n", command);
        int draft;
        getchar();
        scanf("%d", &draft);
        list_add_head(a, draft);
    }
    if (strcmp(command, "add_tail") == 0)
    {
        printf("%s\n", command);
        int draft;
        getchar();
        scanf("%d", &draft);
        list_add_tail(a, draft);
    }
    if (strcmp(command, "del_head") == 0)
    {
        printf("%s\n", command);
        list_del_head(a);
    }
    if (strcmp(command, "del_tail") == 0)
    {
        printf("%s\n", command);
        list_del_tail(a);
    }
    for(struct Element* ukaz = a->Head; ukaz != NULL; ukaz = ukaz->Next)
        printf("%d ", ukaz->Value);
    printf("\n");
    free(a);
    return 0;
}

