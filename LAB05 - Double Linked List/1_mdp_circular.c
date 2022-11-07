#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} 
* last;
void create(int data)
{
    struct node *p, *tmp;
    tmp = malloc(sizeof(struct node));
    tmp->data = data;
    if (last == NULL)
    {
        last = tmp;
        tmp->next = tmp;
    }
    else
    {
        tmp->next = last->next;
        last->next = tmp;
        last = tmp;
    }
}
void display()
{
    if (last == NULL)
    {
        printf("There is not any node in the linked list");
        return;
    }
    else
    {
        struct node *p = last;
        do
        {
            printf("%d \n", p->next->data);
            p = p->next;
        } while (p != last);
    }
}
void insert_beg(int data)
{
    struct node *p, *tmp;
    tmp = malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = last->next;
    last->next = tmp;
}
void insert(int data, int pos)
{
    struct node *p, *tmp;
    tmp = malloc(sizeof(struct node));
    tmp->data = data;
    p = last;
    for (int i = 0; i < (pos - 1); i++)
    {
        p = p->next;
    }
    tmp->next = p->next;
    p->next = tmp;
}
void delete (int data)
{
    struct node *p, *tmp;
    if (last->next->data == data)
    {
        p = last->next;
        last->next = p->next;
        free(p);
        return;
    }
    else
    {
        p = last->next;
        while (p->next != last)
        {
            if (p->next->data == data)
            {
                tmp = p->next;
                p->next = tmp->next;
                free(tmp);
                return;
            }
            p = p->next;
        }
        if (p->next->data == data)
        {
            tmp = p->next;
            p->next = tmp->next;
            last = p;
            free(tmp);
        }
        else
        {
            printf("\n%d is not present\n", data);
        }
    }
}
int main()
{
    int a, data;
    int n;
    int pos;
    while (1)
    {
        printf("\n1. Creating the circular linked list \n2. Display the list \n3. Insert a node at the beginning \n4. Insert any position ");
        printf("\n5. Delete an element from the list\n6. Exit\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("\nEnter the number of Nodes: ");
            scanf("%d", &n);
            printf("\nEnter Data: \n");
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
            printf("\nEnter Data: \n");
            scanf("%d", &data);
            printf("\nEnter Position: \n");
            scanf("%d", &pos);
            insert(data, pos);
            break;
        case 5:
            printf("Enter the Data: ");
            scanf("%d", &data);
            delete (data);
        case 6:
            exit(1);
        default:
            break;
        }
    }
}