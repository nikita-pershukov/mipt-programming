#include <stdio.h>
#include <stdlib.h>

size_t len(const char *a)
{
    size_t res = 0;
    for(; a[res] != 0; res++){} //luche {} vmesto ;, chtobu bulo ponyatno, chto eto pustoy cikl
    return res+1;
}

char* scanf_str()
{
    size_t size = 256;
    char *a = (char*) calloc(size*sizeof(char));
    size_t count = 0;
    char input_c = getchar();
    for(;input_c != '\n'; ++count, input_c = getchar())
    {
        if (count >= size)
        {
            size *= 2;
            a = (char*)realloc(a, size*sizeof(char));
            if (a == NULL)
                exit(666);
        }
        a[count] = input_c;
    }
    a = (char*)realloc(a, (count+1)*sizeof(char));
    if (a == NULL)
        exit(666);
    a[count+1] = 0; //obyazatel'no propisuvat' 0, chtobu bul konec stroki
    return a;
}

int main(void)
{
//    char a[256];
//    scanf("%s", a);
    char *a = scanf_str();
    printf("%d", len(a));
//    printf("Hello World!\n");
    return 0;
}

