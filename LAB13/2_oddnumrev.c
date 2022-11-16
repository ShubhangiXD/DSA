//Reverse only the odd position node elements in a Singly Linked List.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * start, *start1;

void create(int data)
{
    struct node *p, *tmp;
    tmp = malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = NULL;
    if (start == NULL)
    {
        start = tmp;
        return;
    }
    p = start;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = tmp;
}

void display()
{
    printf("\n");
    struct node *p;
    p = start;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void reverse()
{
    int a = 0;
    struct node *p;
    p = start;
    while (p != NULL)
    {
        a = (a * 10) + p->data;
        if (p->next)
            p = p->next->next;
        else
            p = p->next;
    }
    p = start;
    while (a)
    {
        p->data = a % 10;
        a /= 10;
        if (a)
            p = p->next->next;
    }
}

int main()
{
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter Data: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        create(data);
    }
    display();
    start1 = start;
    reverse();
    display();
    return 0;
}