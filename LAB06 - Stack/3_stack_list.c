#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int val)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = val;

    if (top == NULL)
        new->next = NULL;
    else
        new->next = top;
    top = new;
    printf("The node is inserted. \n");
}

int pop()
{
    if (top == NULL)
        printf("\n Stack Underflow. \n");
    else
    {
        struct node *tmp = top;
        int temp_data = top->data;
        top = top->next;
        free(tmp);
        return temp_data;
    }
}

void display()
{
    if (top == NULL)
        printf("\nStack Underflow. \n");
    else
    {
        printf("The stack is: \n");
        struct node *tmp = top;
        while (tmp->next != NULL)
        {
            printf("%d --->", tmp->data);
            tmp = tmp->next;
        }
        printf("%d----> NULL \n\n", tmp->data);
    }
}

int main()
{
    int choice, value;
    printf("Implementation of stack using linked list: \n");
    while (1)
    {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            printf("Popped element is :%d\n", pop());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
}
