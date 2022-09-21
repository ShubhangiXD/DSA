#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *prev, *head, *p;
void display()
{
    if (head == NULL)
        printf ("The list is empty.");
    else
    {
        printf ("The list is: \n);
        struct node *tmp = head;
        while (tmp->next!=NULL)
        {
             printf("%d ----->", tmp->data);
            tmp = tmp->next;
        }
        printf("%d----->NULL", tmp->data);
    }
}
int main()
{
    int n, i;
    printf("Number of elements: \n");
    scanf("%d", &n);
    head = NULL;
    for (i = 0; i < n; i++)
    {
        p = malloc(sizeof(struct node));
        scanf("%d", &p->data);
        p->next = NULL;
        if (head == NULL)
            head = p;
        else
            prev->next = p;
        prev = p;
    }
    display();
    return 0;
}
