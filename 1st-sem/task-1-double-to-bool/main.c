#include <stdio.h>

typedef double mytype;

void print_byts(const void* input_void, int size)
{
    char* c = (char*) input_void;
    printf("%lf : ", *((mytype*) input_void));
        for(int j=size-1;j>=0;j--)
        {
            for(int i=128;i;i>>=1)
            {
                if(i & c[j])
                {
                    printf("1");
                }
                else
                {
                    printf("0");
                }
            }
            printf(" ");
        }
        printf("\n");
}

int main(void)
{
    mytype *n = (mytype*) malloc(sizeof(mytype));
    if(n==NULL)
        exit(666);
    scanf("%lf", n);
    print_byts(n, sizeof(mytype));
    return 0;
}

