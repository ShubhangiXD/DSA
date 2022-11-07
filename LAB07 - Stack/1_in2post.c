#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int top;
#define MAX 20
char infix[MAX];
char postfix[MAX];
int stack[MAX];

int is_empty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void push(int symbol)
{
    if (top > MAX)
    {
        printf("\n\nOVERFLOW!");
        exit(1);
    }
    stack[++top] = symbol;
}

int priority(char symbol)
{
    switch (symbol)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int pop()
{
    if (is_empty())
    {
        printf("\n\nUNDERFLOW!");
        exit(1);
    }
    return (stack[top--]);
}

void infixtopostfix()
{
    int i, p = 0;
    char next, symbol;
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            while ((next = pop() != '('))
                postfix[p++] = next;
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
            while (!is_empty() && priority(stack[top] >= priority(symbol)))
                postfix[p++] = pop();
            push(symbol);
            break;
        default:
            postfix[p++] = symbol;
        }
    }
    while (!is_empty())
        postfix[p++] = pop();
    postfix[p] = '\0';
}

int eval_post()
{
    int a, b, tmp, result, i;
    for (i = 0; i < strlen(postfix); i++)
    {
        if (postfix[i] <= 9 && postfix[i] >= 0)
            push(postfix[i] - '0');
        else
        {
            a = pop();
            b = pop();

            switch (postfix[i])
            {
            case '+':
                tmp = b + a;
                break;
            case '-':
                tmp = b - a;
                break;
            case '*':
                tmp = b * a;
                break;
            case '/':
                tmp = b / a;
                break;
            case '%':
                tmp = b % a;
                break;
            case '^':
                tmp = pow(b, a);
                break;
            }
            push(tmp);
        }
        result = pop();
        return result;
    }
}

void main()
{
    int value;
    top = -1;
    printf("Enter the infix expression: \n");
    gets(infix);
    infixtopostfix();
    printf("The postfix expression is: \n");
    printf("%s", postfix);
    value = eval_post();
    printf("%d", value);
}