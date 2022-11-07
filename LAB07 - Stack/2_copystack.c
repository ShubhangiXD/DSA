#include <stdio.h>
void push(int data, int *top, int stack[], int size)
{
    if (*top == size - 1)
    {
        printf("\n\nOverflow!");
        return;
    }
    else
    {
        (*top)++;
        stack[*top] = data;
    }
}

void pop(int *top, int stack[])
{
    if (*top == -1)
    {
        printf("\n\nUnderflow!");
        return;
    }
    else
        (*top)--;
}

void display(int top, int stack[])
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty");
        return;
    }
    else
    {
        printf("\nElements: \n");
        for (i = top; i >= 0; i--)
            printf("%d  ", stack[i]);
    }
    printf("\n");
}

int main()
{
    int top = -1, t = -1;
    int n, i, d;
    printf("Enter the number of elements: \n");
    scanf("%d", &n);
    int stack[n], s[n];
    printf("Enter the data for stack:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &d);
        push(d, &top, stack, n);
    }
    display(top, stack);
    int tmp, c = 0;
    while (c != top)
    {
        tmp = stack[top];
        pop(&top, stack);
        for (i = top; i > c; i--)
        {
            push(stack[top], &t, s, n);
            pop(&top, stack);
        }
        push(tmp, &top, stack, n);
        for (i = t; i >= 0; i--)
        {
            push(s[t], &top, stack, n);
            pop(&t, s);
        }
        c++;
    }
    for (i = top; i >= 0; i--)
    {
        push(stack[top], &t, s, n);
        pop(&top, stack);
    }
    printf("New Stack:");
    display(t, s);
    return 0;
}