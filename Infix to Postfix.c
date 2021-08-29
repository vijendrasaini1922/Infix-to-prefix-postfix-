// program for Infix to Postfix using stack

#include <stdio.h>
#include <stdlib.h>
#define MAX_NO 20
int top = -1;
char arr[MAX_NO] = {0};

int push(char, char arr[]);
int pop(char arr[]);
int prece(char x);

int main()
{
    char exp[20] = {0};
    char output[20] = {0};
    printf("\n===============1.A===============\n");
    printf("Enter The infix Expression: ");
    gets(exp);

    push('#', arr);

    int i = 0, j = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '(')
            push(exp[i], arr);
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            if (prece(exp[i]) > prece(arr[top]))
                push(exp[i], arr);
            else if (prece(exp[i]) <= prece(arr[top]))
            {
                while (prece(exp[i]) <= prece(arr[top]))
                {
                    output[j] = arr[top];
                    j++;
                    pop(arr);
                }
                push(exp[i], arr);
            }
        }
        else if (exp[i] == ')')
        {
            while (arr[top] != '(')
            {
                output[j] = arr[top];
                j++;
                pop(arr);
            }
            pop(arr);
        }
        else
        {
            output[j] = exp[i];
            j++;
        }
        i++;
    }
    while (arr[top] != '#')
    {
        output[j] = arr[top];
        j++;
        pop(arr);
    }

    output[j] = '\0';
    printf("\nOur required postfix expression: ");
    puts(output);

    return 0;
}

int push(char x, char arr[])
{
    if (top == MAX_NO - 1)
        printf("Overflow Condition!!");
    else
    {
        top++;
        arr[top] = x;
    }
}

int pop(char arr[])
{
    if (top == -1)
        printf("Underflow Condition!!");
    else
        top--;
}

int prece(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '^')
        return 3;
    else
        return 0;
}