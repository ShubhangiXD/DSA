#include <stdio.h>
#include <stdlib.h>

struct node
{
    int n;
    struct node *link;
};
struct node *start[3];

void create(int data, int i)
{
    struct node *p, *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->n = data;
    tmp->link = NULL;
    if (start[i] == NULL)
    {
        start[i] = tmp;
        return;
    }
    else
    {
        p = start[i];
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = tmp;
    }
}

void display(int i)
{
    printf("\n");
    if (start[i] == NULL)
    {
        printf("No data is available");
        return;
    }
    else
    {
        struct node *p = start[i];
        do
        {
            printf("%d ", p->n);
            p = p->link;
        } while (p != NULL);
    }
}

void subtract()
{
    struct node *p = start[0];
    struct node *q = start[1];
    create(p->n - q->n, 2);
    struct node *r = start[2];
    while (p->link != NULL)
    {
        p = p->link;
        q = q->link;
        int s = p->n - q->n;
        if (s < 0)
        {
            r->n -= 1;
            int t = 10 + (p->n);
            create(t - q->n, 2);
        }
        else
        {
            create(s, 2);
        }
        r = r->link;
    }
}

int main()
{
    start[0] = NULL;
    start[1] = NULL;
    start[2] = NULL;
    int data;
    printf("Enter two same digit number: ");
    for (int i = 0; i < 2; i++)
    {
        scanf("%d", &data);
        int c = 1, r = data;
        while (r)
        {
            c *= 10;
            r /= 10;
        }
        c /= 10;
        while (data)
        {
            create(data / c, i);
            data %= c;
            c /= 10;
        }
    }
    printf("First number is:");
    display(0);
    printf("\nSecond number is:");
    display(1);
    subtract();
    printf("\nThird node is:");
    display(2);
    return 0;
}