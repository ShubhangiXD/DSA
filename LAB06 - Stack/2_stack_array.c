#include <stdio.h>
#include <stdlib.h>
int top = -1;
int stack[10];

void push()
{
    if (top == 9)
    {
        printf("\nOverflow");
        return;
    }
    int data;
    printf("\nEnter data: ");
    scanf("%d", &data);
    top += 1;
    stack[top] = data;
}
void pop()
{
    if (top == -1)
    {
        printf("\nUnderflow");
        return;
    }
    top--;
    printf("The popped element is %d", stack[top]);
}
void display()
{
    printf("\n");
    if (top == -1)
    {
        printf("Stack is empty");
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Quit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("\nPlease input valid choice");
            break;
        }
    }
    return 0;
}