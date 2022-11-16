/*Delete all the nodes in a doubly linked list, where the data element of the node is greater than 
the data element of all its previous nodes and is less than the data element of all the next nodes*/
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
    printf("\n");
    struct node *p = start;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void delete ()
{
    struct node *p = start->next;
    while (p->next != NULL)
    {
        int c = 0, d = 0;
        struct node *q, *r;
        q = p->prev;
        r = p->next;
        while (q != NULL)
        {
            if (q->data >= p->data)
            {
                c = 1;
                break;
            }
            q = q->prev;
        }
        while (r != NULL)
        {
            if (r->data <= p->data)
            {
                d = 1;
                break;
            }
            r = r->next;
        }
        if (c == 0 && d == 0)
        {
            struct node *tmp = p;
            p->prev->next = p->next;
            p->next->prev = p->prev;
            p = p->prev;
            free(tmp);
        }
        p = p->next;
    }
}

int main()
{
    int a, n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter data: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        create(a);
    }
    display();
    delete ();
    display();
    return 0;
}