#include <stdio.h>

void chat_to_bool(char input)
{
    for (int i = 0; i < 8; ++i)
        printf("%d", (input & 1<<(7-i)) != 0);
}

int main(void)
{
    for (char input= 32; input <= 'z'; ++input)
    {
        printf("%c ", input);
        chat_to_bool(input);
        printf("\n");
    }
    getchar();
    return 0;
}

