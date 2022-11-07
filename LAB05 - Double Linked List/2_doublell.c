#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
} * start;

void create(int data)
{
    struct node *p, *q;
    p = malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;
    if (start == NULL)
    {
        start = p;
        p->prev = NULL;
    }
    else
    {
        q = start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
        p->prev = q;
    }
}

void display()
{
    struct node *p = start;
    if (start == NULL)
    {
        printf("\nNo data is available");
        return;
    }
    printf("\n");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void insert_beg(int data)
{
    struct node *tmp;
    tmp = malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = start;
    tmp->prev = NULL;
    start->prev = tmp;
    start = tmp;
}

void insert(int data, int pos)
{
    struct node *tmp, *p;
    tmp = malloc(sizeof(struct node));
    tmp->data = data;
    p = start;
    for (int i = 1; i < pos; i++)
    {
        p = p->next;
    }
    if (p->next == NULL)
    {
        tmp->next = NULL;
    }
    else
    {
        tmp->next = p->next;
        p->next->prev = tmp;
    }
    tmp->prev = p;
    p->next = tmp;
}

int main()
{
    int a, data;
    int n;
    int pos;
    while (1)
    {
        printf("\n1. create the list\t2. display\n3. Insert at beginning\t4. Insert any position");
        printf("\n5. exit\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:

            printf("\nEnter the number of nodes: ");
            scanf("%d", &n);
            printf("\nEnter data: \n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &data);
                create(data);
            }
            break;
        case 2:
            display();
            break;
        case 3:
            printf("\nEnter data: \n");
            scanf("%d", &data);
            insert_beg(data);
            break;
        case 4:

            printf("\nEnter data: \n");
            scanf("%d", &data);
            printf("\nEnter position: \n");
            scanf("%d", &pos);
            insert(data, pos);
            break;
        case 5:
            exit(1);
        default:
            break;
        }
    }
    return 0;
}