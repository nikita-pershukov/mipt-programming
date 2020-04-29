#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_NULL(void* ukaz)
{
    if (ukaz == NULL)
    {
        printf("---666---\n");
        exit(666);
    }
}

int get_count(const char* a, const char* find)
{
    if (strstr(a, find) == NULL)
        return 1;
    return 1 + get_count(strstr(a, find)+strlen(find), find);
}

char** split(const char* a, const char* find)
{
    int count = get_count(a, find);
    char* b = (char*) a;
    char** res = (char**) malloc ((count)*sizeof(char*));
    check_NULL(res);
    for(int i = 0; i < count; ++i)
    {
        printf("---%d/%d---\n", i+1, count);
        char* ukaz_str = strstr(b, find);
        printf("---ukaz---%ld---\n", ukaz_str);
        int size_str = (ukaz_str != NULL) ? (ukaz_str - b) : strlen(b);
        printf("---size---%d---\n", size_str);
        res[i] = (char*) malloc((size_str+1)*sizeof(char));
        printf("1 - malloc\n");
        check_NULL(res[i]);
        printf("2 - check\n");
        strncpy(res[i], b, size_str);
        printf("3 - strncpy\n");
        res[i][size_str] = '\0';
        printf("4 - /0\n");
        b += size_str+strlen(find);
        printf("5 - refresh b\n");
    }
    printf("---!!!---\n");
    return res;
}

int main(void)
{
//    char *a = (char*) malloc(256*sizeof(char));
    char a[256];
    check_NULL(a);
//    char *find = (char*) malloc(256*sizeof(char));
    char find[256];
    check_NULL(find);
    scanf("%s", a);
    getchar();
    scanf("%s", find);
    printf("count = %zd\n", get_count(a, find));
    int count = get_count(a, find);
    char **res = split(a, find);
    printf("---start printf---\n");
    for(int i = 0; i < count; ++i)
        printf("%s\n", res[i]);
    printf("---printf successful---\n");
    printf("---start free array---\n");
    for(int i = 0; i < count; ++i)
        free(res[i]);
    printf("---free array successful---\n");
    printf("---start free res---\n");
    free(res);
//    printf("---start free a---\n");
//    free(a);
//    printf("---start free find---\n");
//    free(find);
    printf("---ended successful---\n");
    return 0;
}

