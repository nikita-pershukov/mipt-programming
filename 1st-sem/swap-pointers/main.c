#include <stdio.h>

void swap (void*a, void*b, size_t size)
{
    char *c = (char*) a; //chtobu rabotat' s *a (s void nal'zya skladuvat'
    char *d = (char*) b;
    for (size_t i = 0; i < size; ++i)
    {
        char draft = *(c+i);
        *(c+i) = *(d+i);
        *(d+i) = draft;
    }
}

int main(void)
{

    char c, d;
    scanf("%c %c", &c, &d); //Obyazatel'no v shablone propisat' " " - inache chitaet probel i enter za symbol
//    scanf("%c", &d);
//    c = getchar();
//    getchar();
//    d = getchar();
    swap(&c, &d, sizeof(char));
    printf("%c_%c\n", c, d);
    printf("---pause---\n");
    printf("---start---\n");
    int a, b;
    scanf("%d %d", &a, &b);
    swap(&a, &b, sizeof(int));
    printf("%d_%d\n", a, b);
    return 0;
}

