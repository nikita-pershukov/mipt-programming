#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Stack
{
    struct Node
    {
        struct Node* prev;
        char* value;
    };
    struct Node * last;
};

int is_empty(struct Stack* stack)
{
    if (stack->last == NULL) return 1;
    else return 0;
}
void add(struct Stack* stack, char* oper)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->prev = stack->last;
    node->value = oper;
    stack->last = node;
}
char* pop(struct Stack* stack)
{
    if (stack->last != NULL)
    {
        struct Node* temp = stack->last;
        stack->last = stack->last->prev;
        char* str = (char*) malloc(strlen(temp->value)*sizeof(char));
        for(int i = 0; i < strlen(temp->value); ++i)
        {
            str[i] = temp->value[i];
        }
        str[strlen(temp->value)] = '\0';
        free(temp->value);
        free(temp);
        return str;
    }
    else return 0;
}

int main()
{
    struct Stack stack;
    stack.last = NULL;
    char str[1000];
    char out[1000];
    scanf("%s", str);
    int count = 0;
    for (int i = 0; i < strlen(str); ++i)
    {
        if ((str[i] >= '0') && (str[i] <= '9'))
        {
            if ((str[i+1] >= '0') && (str[i+1] <= '9'))
            {
                out[count] = str[i];
                ++count;
            }
            else
            {
                out[count] = str[i];
                out[count+1] = ' ';
                count += 2;
            }
        }else
        if ((str[i] == '+') || (str[i] == '-'))
        {
            if (!is_empty(&stack))
            if((stack.last->value[0] == '*') || (stack.last->value[0]
                == '/') || (stack.last->value[0] == '-') || (stack.last->value[0] == '+'))
            {
                char* temp = pop(&stack);
                for (int i = 0; i < strlen(temp); ++i)
                {
                    out[count] = temp[i];
                    ++count;
                }
                free(temp);
                out[count++] = ' ';
            }
            char* temp = (char*) malloc(2*sizeof(char));
            temp[0] = str[i];
            temp[1] = '\0';
            add(&stack, temp);
        }else
        if ((str[i] == '*') || (str[i] == '/'))
        {
            if (!is_empty(&stack))
            if((stack.last->value[0] == '*') || (stack.last->value[0]
                == '/'))
            {
                char* temp = pop(&stack);
                for (int i = 0; i < strlen(temp); ++i)
                {
                    out[count] = temp[i];
                    ++count;
                }
                free(temp);
                out[count++] = ' ';
            }
            char* temp = (char*) malloc(2*sizeof(char));
            temp[0] = str[i];
            temp[1] = '\0';
            add(&stack, temp);
        }else
        if (str[i] == '(')
        {
            char* temp = (char*) malloc(2*sizeof(char));
            temp[0] = str[i];
            temp[1] = '\0';
            add(&stack, temp);
        }else
        if (str[i] == ')')
        {
            while(stack.last->value[0] != '(')
            {
                char* temp = pop(&stack);
                for (int i = 0; i < strlen(temp); ++i)
                {
                    out[count] = temp[i];
                    ++count;
                }
                free(temp);
                out[count++] = ' ';
            }
            char* temp = pop(&stack);
            free(temp);
            if  (!is_empty(&stack))
            if ((stack.last->value[0] == '+') || (stack.last->value[0]
                == '-'))
            {
                char* temp = pop(&stack);
                for (int i = 0; i < strlen(temp); ++i)
                {
                    out[count] = temp[i];
                    ++count;
                }
                free(temp);
                out[count++] = ' ';
            }
        }
    }
    while(!is_empty(&stack))
    {
        char* temp = pop(&stack);
        for (int i = 0; i < strlen(temp); ++i)
        {
            out[count] = temp[i];
            ++count;
        }
        free(temp);
        out[count++] = ' ';
    }
    out[count] = '\0';
    printf("%s\n", out);
    return 0;
}
