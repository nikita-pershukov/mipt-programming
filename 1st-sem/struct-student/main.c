#include <stdio.h>
#include <stdio.h>

struct student
{
    int room;
    char groop;
};

int main(void)
{
    size_t n;
    scanf("%zd", &n);
    struct student* a = (struct student*) malloc(n*sizeof(struct student));
    if (a == NULL)
        exit(666);
    int b[4];
    for (int i = 0; i<n; ++i)
    {
        scanf("%d %c", &a[i].room, &a[i].groop);
    }
    int room;
    scanf("%d", &room);
    for(int i = 0; i<4; ++i)
        b[i] = 0;
    for(int i = 0; i<n; ++i)
        if(room == a[i].room)
            ++b[a[i].groop-'a'];
    for(int i = 0; i<4; ++i)
        if(b[i])
            printf("%d%c ", b[i], i+'a');
    printf("\n");
    return 0;
}

