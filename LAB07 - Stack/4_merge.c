#include <stdio.h>
void push(int data, int *top, int stack[], int size)
{
    if (*top == size - 1)
    {
        printf("\nOverflow!");
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
        printf("\nUnderflow!");
        return;
    }
    else
    {
        printf("The popped element is: %d \n", stack[*top]);
        (*top)--;
    }
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
        printf("\nElement: ");
        for (i = top; i >= 0; i--)
            printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    int s = -1, t = -1;
    int n, m, i, d;

    printf("Enter the number of elements in the first stack: \n");
    scanf("%d", &n);
    printf("Enter the number of elemets in the second stack: \n");
    scanf("%d", &m);
    int s1[n + m];
    int s2[m];

    printf("Enter the data for the first stack: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &d);
        push(d, &s, s1, n);
    }

    printf("Enter the data for the second stack: \n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &d);
        push(d, &t, s2, m);
    }
    display(s, s1);
    display(t, s2);

    int tmp = t;
    for (i = 0; i < m; i++)
        push(s2[tmp--], &s, s1, n + m);
    display(s, s1);
    return 0;
}