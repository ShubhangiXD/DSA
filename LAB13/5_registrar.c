#include <stdio.h>
#include <stdlib.h>

struct node
{
    char sub[20];
    int section;
    int credit;
    struct node *next;
};

struct student
{
    int id;
    struct node *next;
};

void create(struct student *root, char s[20], int sec, int cre)
{
    struct node *p, *r;
    p = malloc(sizeof(struct node));
    p->next = NULL;
    for (int i = 0; s[i] != '\0'; i++)
        p->sub[i] = s[i];
    p->section = sec;
    p->credit = cre;
    if (root->next == NULL)
    {
        root->next = p;
        return;
    }
    r = root->next;
    while (r->next != NULL)
    {
        r = r->next;
    }
    r->next = p;
}

void display(int n, struct student root[])
{
    for (int i = 0; i < n; i++)
    {
        if (root[i].next == NULL)
            printf("\nstudent of id %d isnot enrolled in any section", root[i].id);
        else
        {
            struct node *p = root[i].next;
            printf("\nstudent of id %d is taking section ", root[i].id);
            while (p != NULL)
            {
                printf("%d of %s for %d credits,", p->section, p->sub, p->credit);
                p = p->next;
            }
        }
    }
}

int main()
{
    int n, a, b, d, m;
    char c[20];
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct student start[n];
    for (int i = 0; i < n; i++)
    {
        start[i].next = NULL;
        printf("Enter id: ");
        scanf("%d", &a);
        start[i].id = a;
        printf("\nEnter the number of course enrolled: ");
        scanf("%d", &m);
        while (m--)
        {
            printf("Enter section: ");
            scanf("%d", &b);
            printf("Enter subject code: \n");
            scanf("%s", &c);
            printf("Enter credit: ");
            scanf("%d", &d);
            create(&start[i], c, b, d);
        }
    }
    display(n, &start[0]);
    return 0;
}