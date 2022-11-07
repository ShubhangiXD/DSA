#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coef;
    int exp;
    struct node *link;
};

struct node *insert(struct node *start, int co, int ex)
{
    struct node *tmp, *q;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->coef = co;
    tmp->exp = ex;

    if (start == NULL || ex > start->exp)
    {
        tmp->link = start;
        start = tmp;
    }
    else
    {
        q = start;
        while (q->link != NULL && q->link->exp >= ex)
        {
            q = q->link;
            tmp->link = q->link;
            q->link = tmp;
        }
    }
    return start;
}

struct node *create(struct node *start)
{
    int n, ex, co;
    printf("Enter the number of terms:");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("Enter the co-efficient and the exponent for term %d: \n", i);
        scanf("%d %d", &co, &ex);
        start = insert(start, co, ex);
    }
    return start;
}

void display(struct node *q)
{
    while (q != NULL)
    {
        printf("%dx^%d", q->coef, q->exp);
        q = q->link;
        if (q != NULL)
            printf(" + ");
        else
            printf("\n");
    }
}

void poly_add(struct node *p1, struct node *p2)
{
    struct node *start3;
    start3 = NULL;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp > p2->exp)
        {
            start3 = insert(start3, p1->coef, p1->exp);
            p1 = p1->link;
        }
        else if (p2->exp > p1->exp)
        {
            start3 = insert(start3, p2->coef, p2->exp);
            p2 = p2->link;
        }
        else if (p1->exp == p2->exp)
        {
            start3 = insert(start3, p2->coef + p1->coef, p2->exp);
            p1 = p1->link;
            p2 = p2->link;
        }
    }
    while (p1 != NULL)
    {
        start3 = insert(start3, p1->coef, p1->exp);
        p1 = p1->link;
    }
    while (p2 != NULL)
    {
        start3 = insert(start3, p2->coef, p2->exp);
        p2 = p2->link;
    }
    display(start3);
}

void poly_mult(struct node *p1, struct node *p2)
{
    struct node *start3 = NULL;
    struct node *p2_beg = p2;
    while (p1 != NULL)
    {
        p2 = p2_beg;
        while (p2 != NULL)
        {
            start3 = insert(start3, p1->coef * p2->coef, p1->exp + p2->exp);
            p2 = p2->link;
        }
        p1 = p1->link;
    }
    display(start3);
}

void main()
{
    struct node *start1 = NULL;
    struct node *start2 = NULL;
    start1 = create(start1);
    start2 = create(start2);
    printf("The two polynomials are: \n");
    display(start1);
    display(start2);
    printf("The addition of the two terms is: \n");
    poly_add(start1, start2);
    printf("The multiplication of the two terms is: \n");
    poly_mult(start1, start2);
}