#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
} * start;

void create(int data)
{
    struct node *p, *tmp;
    tmp = malloc(sizeof(struct node));
    tmp->num = data;
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
    struct node *p;
    p = start;
    if (start == NULL)
    {
        printf("The list is empty.");
        return;
    }
    while (p != NULL)
    {
        printf("%d ", p->num);
        p = p->next;
    }
}

void sum()
{
    struct node *p, *q, *r;
    int count = 0;
    p = start;
    q = p;
    r = p->next->next;
    while (r != NULL)
    {
        do
        {
            int s = 0;
            while (q != r)
            {
                s += q->num;
                q = q->next;
            }
            if (s == r->num)
            {
                count++;
                printf("\n{");
                while (p != r)
                {
                    printf("%d ", p->num);
                    p = p->next;
                }
                printf("}");
            }
            else
            {
                p = p->next;
                q = p;
            }
        } while (p != r);
        r = r->next;
        p = start;
        q = p;
    }
    printf("\nNumber of summation groups are: %d", count);
}

int main()
{
    start = NULL;
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter data: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        create(data);
    }
    printf("\nThe values in each summation group are:");
    sum();
    return 0;
}